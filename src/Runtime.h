#pragma once
/**
 * @file Runtime.h
 * @brief Minimal statevector-based runtime for an OpenQASM 3 simulator.
 *
 * This class maintains:
 *  - a mapping from named qubit registers to absolute wire indices,
 *  - a full-statevector (complex<double>) in little-endian bit ordering
 *    (wire 0 is the least-significant bit),
 *  - simple classical storage: bit arrays, single bools, and integers,
 *  - a handful of quantum operations (X, H, CX) plus a generic 1-qubit apply,
 *  - mid-circuit measurement with collapse, reset, and RNG seeding,
 *  - optional dump helpers for statevector and classical registers.
 *
 * The API is intentionally small and header-only to ease integration with a
 * parse-tree visitor or a compiled IR. All methods throw std::runtime_error
 * on invalid usage (unknown registers, out-of-range indices, etc.).
 */

#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <ostream>
#include <random>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Runtime {
  using cplx = std::complex<double>;

public:
  /// Construct with a non-deterministic seed.
  Runtime() : rng_(std::random_device{}()) {}

  /// Set the RNG seed (useful for deterministic tests).
  void setSeed(std::uint64_t seed) noexcept { rng_.seed(seed); }

  // --------------------------------------------------------------------------
  // Quantum allocation and mapping
  // --------------------------------------------------------------------------

  /**
   * @brief Allocate a named qubit register of size @p n.
   *
   * Extends the current statevector by tensoring |0...0> on the new wires.
   * If this is the first allocation, initializes |psi> = |0...0>.
   *
   * @param name Register identifier (must be unique).
   * @param n    Number of qubits (> 0).
   */
  void allocQubits(const std::string& name, int n) {
    if (n <= 0) throw std::runtime_error("allocQubits: size must be > 0");
    if (qregs_.count(name)) throw std::runtime_error("allocQubits: qubit register '" + name + "' already exists");

    const int base = numQubits_;
    qregs_.emplace(name, QReg{base, n});
    numQubits_ += n;

    const std::size_t oldSize = psi_.size();
    const std::size_t newSize = std::size_t{1} << numQubits_;
    if (oldSize == 0) {
      psi_.assign(newSize, cplx{0.0, 0.0});
      psi_[0] = cplx{1.0, 0.0};
    } else {
      // Extend |psi> by |0...0> on the new wires.
      std::vector<cplx> newpsi(newSize, cplx{0.0, 0.0});
      for (std::size_t i = 0; i < oldSize; ++i) newpsi[i] = psi_[i];
      psi_.swap(newpsi);
    }
  }

  /**
   * @brief Translate a logical index within a named register to an absolute wire.
   * @throws std::runtime_error if the register does not exist or idx is out of range.
   */
  int qubitIndex(const std::string& qname, int idx) const {
    const auto it = qregs_.find(qname);
    if (it == qregs_.end()) throw std::runtime_error("qubitIndex: unknown qubit register '" + qname + "'");
    if (idx < 0 || idx >= it->second.size) throw std::runtime_error("qubitIndex: index out of range");
    return it->second.base + idx;
  }

  /// Number of allocated qubits (wires) in the global state.
  int numQubits() const noexcept { return numQubits_; }

  /// Read-only access to the full statevector.
  const std::vector<cplx>& state() const noexcept { return psi_; }

  /// Size of a named qubit register.
  int qregSize(const std::string& name) const { return qregs_.at(name).size; }

  /// Base (absolute starting wire) of a named qubit register.
  int qregBase(const std::string& name) const { return qregs_.at(name).base; }

  /**
   * @brief Return all absolute wire indices belonging to @p name.
   * @throws std::runtime_error if the register does not exist.
   */
  std::vector<int> allQubits(const std::string& name) const {
    const auto it = qregs_.find(name);
    if (it == qregs_.end()) throw std::runtime_error("allQubits: unknown qubit register '" + name + "'");
    std::vector<int> v;
    v.reserve(it->second.size);
    for (int i = 0; i < it->second.size; ++i) v.push_back(it->second.base + i);
    return v;
  }

  // --------------------------------------------------------------------------
  // Classical storage (bit arrays, bool scalars, int scalars)
  // --------------------------------------------------------------------------

  /// Declare bit array: bit[n] name;
  void declareBits(const std::string& name, int n) {
    if (n <= 0) throw std::runtime_error("declareBits: size must be > 0");
    ensureNewIdentifier(name);
    bits_.emplace(name, std::vector<int>(static_cast<std::size_t>(n), 0));
  }

  /// Declare bool scalar: bool name;
  void declareBool(const std::string& name) {
    ensureNewIdentifier(name);
    bools_.emplace(name, false);
  }

  /// Declare int scalar: int name = v;
  void declareInt(const std::string& name, long long v = 0) {
    ensureNewIdentifier(name);
    ints_.emplace(name, v);
  }

  // -- setters / getters ------------------------------------------------------

  /// Set bit[name][i] = v (0/1).
  void setBit(const std::string& name, int i, int v) {
    auto it = bits_.find(name);
    if (it == bits_.end()) throw std::runtime_error("setBit: unknown bit array '" + name + "'");
    if (i < 0 || i >= static_cast<int>(it->second.size())) throw std::runtime_error("setBit: index out of range");
    it->second[static_cast<std::size_t>(i)] = (v != 0);
  }

  /// Get bit[name][i] (0/1).
  int getBit(const std::string& name, int i) const {
    const auto it = bits_.find(name);
    if (it == bits_.end()) throw std::runtime_error("getBit: unknown bit array '" + name + "'");
    if (i < 0 || i >= static_cast<int>(it->second.size())) throw std::runtime_error("getBit: index out of range");
    return it->second[static_cast<std::size_t>(i)];
  }

  /// Set bool[name] = v.
  void setBool(const std::string& name, bool v) {
    auto it = bools_.find(name);
    if (it == bools_.end()) throw std::runtime_error("setBool: unknown bool '" + name + "'");
    it->second = v;
  }

  /// Get bool[name].
  bool getBool(const std::string& name) const {
    const auto it = bools_.find(name);
    if (it == bools_.end()) throw std::runtime_error("getBool: unknown bool '" + name + "'");
    return it->second;
  }

  /// Set int[name] = v.
  void setInt(const std::string& name, long long v) {
    auto it = ints_.find(name);
    if (it == ints_.end()) throw std::runtime_error("setInt: unknown int '" + name + "'");
    it->second = v;
  }

  /// Get int[name].
  long long getInt(const std::string& name) const {
    const auto it = ints_.find(name);
    if (it == ints_.end()) throw std::runtime_error("getInt: unknown int '" + name + "'");
    return it->second;
  }

  /// Presence checks (useful for dynamic typing in the executor).
  bool hasBit(const std::string& n) const noexcept { return bits_.count(n) != 0; }
  bool hasBool(const std::string& n) const noexcept { return bools_.count(n) != 0; }
  bool hasInt(const std::string& n) const noexcept { return ints_.count(n) != 0; }

  // --------------------------------------------------------------------------
  // Quantum operations
  // --------------------------------------------------------------------------

  /// Pauli-X on wire q.
  void x(int q) {
    const std::size_t N = psi_.size();
    const std::size_t m = std::size_t{1} << q;
    for (std::size_t i = 0; i < N; i += (m << 1)) {
      for (std::size_t j = 0; j < m; ++j) {
        std::swap(psi_[i + j], psi_[i + j + m]);
      }
    }
  }

  /// Hadamard on wire q.
  void h(int q) {
    static const double invsqrt2 = 1.0 / std::sqrt(2.0);
    const std::size_t N = psi_.size();
    const std::size_t m = std::size_t{1} << q;
    for (std::size_t i = 0; i < N; i += (m << 1)) {
      for (std::size_t j = 0; j < m; ++j) {
        const auto a = psi_[i + j];
        const auto b = psi_[i + j + m];
        psi_[i + j]     = (a + b) * invsqrt2;
        psi_[i + j + m] = (a - b) * invsqrt2;
      }
    }
  }

  /// Controlled-X with control c and target t (c != t).
  void cx(int c, int t) {
    if (c == t) throw std::runtime_error("cx: control and target must differ");
    const std::size_t N = psi_.size();
    const std::size_t cm = std::size_t{1} << c;
    const std::size_t tm = std::size_t{1} << t;
    for (std::size_t i = 0; i < N; ++i) {
      if ((i & cm) && !(i & tm)) {
        std::swap(psi_[i], psi_[i | tm]);
      }
    }
  }

  /**
   * @brief Apply an arbitrary single-qubit unitary to wire @p q.
   *
   * The unitary is specified in row-major order:
   *   [[u00, u01],
   *    [u10, u11]]
   */
  void apply1(int q, cplx u00, cplx u01, cplx u10, cplx u11) {
    const std::size_t N = psi_.size();
    const std::size_t m = std::size_t{1} << q;
    for (std::size_t i = 0; i < N; i += (m << 1)) {
      for (std::size_t j = 0; j < m; ++j) {
        const auto a = psi_[i + j];
        const auto b = psi_[i + j + m];
        psi_[i + j]     = u00 * a + u01 * b;
        psi_[i + j + m] = u10 * a + u11 * b;
      }
    }
  }

  /**
   * @brief Projective Z-basis measurement on wire @p q with collapse.
   * @return 0 or 1, sampled according to |psi|^2 on the measured subspace.
   */
  int measure(int q) {
    const std::size_t N = psi_.size();
    const std::size_t m = std::size_t{1} << q;

    long double p1 = 0.0L;
    for (std::size_t i = 0; i < N; ++i) {
      if (i & m) p1 += std::norm(psi_[i]);
    }

    std::bernoulli_distribution dist(static_cast<double>(p1));
    const int r = dist(rng_) ? 1 : 0;

    long double norm = 0.0L;
    if (r == 0) {
      for (std::size_t i = 0; i < N; ++i) if (i & m) psi_[i] = cplx{0.0, 0.0};
      for (const auto& a : psi_) norm += std::norm(a);
    } else {
      for (std::size_t i = 0; i < N; ++i) if (!(i & m)) psi_[i] = cplx{0.0, 0.0};
      for (const auto& a : psi_) norm += std::norm(a);
    }

    const double s = (norm > 0.0L) ? 1.0 / std::sqrt(static_cast<double>(norm)) : 0.0;
    for (auto& a : psi_) a *= s;

    return r;
  }

  /// Reset wire @p q to |0> (measure + conditional X).
  void reset(int q) {
    const int r = measure(q);
    if (r == 1) x(q);
  }

  // --------------------------------------------------------------------------
  // Dump helpers (optional)
  // --------------------------------------------------------------------------

  /// Dump non-negligible amplitudes of the statevector to @p out.
  void dumpState(std::ostream& out, double eps = 1e-12) const {
    out << "== Statevector (" << numQubits_ << " qubits) ==\n";
    for (std::size_t i = 0; i < psi_.size(); ++i) {
      const double p = std::norm(psi_[i]);
      if (p > eps) {
        out << i << ": " << psi_[i] << "    |amp|^2=" << p << "\n";
      }
    }
  }

  /// Dump classical registers in a human-readable form to @p out.
  void dumpClassical(std::ostream& out) const {
    out << "== Classical registers ==\n";
    for (const auto& kv : ints_)  out << "int   " << kv.first << " = " << kv.second << "\n";
    for (const auto& kv : bools_) out << "bool  " << kv.first << " = " << (kv.second ? "true" : "false") << "\n";
    for (const auto& kv : bits_) {
      out << "bit[" << kv.second.size() << "] " << kv.first << " = [";
      for (std::size_t i = 0; i < kv.second.size(); ++i) {
        if (i) out << ",";
        out << kv.second[i];
      }
      out << "]\n";
    }
  }

private:
  /// Ensure @p name isn’t already used by any classical storage.
  void ensureNewIdentifier(const std::string& name) const {
    if (bits_.count(name) || bools_.count(name) || ints_.count(name)) {
      throw std::runtime_error("declare: duplicate classical identifier '" + name + "'");
    }
  }

  struct QReg { int base; int size; };

  int numQubits_ = 0;                        ///< number of allocated wires
  std::vector<cplx> psi_;                    ///< full statevector (size = 2^numQubits_)
  std::unordered_map<std::string, QReg> qregs_;                 ///< qubit registers
  std::unordered_map<std::string, std::vector<int>> bits_;      ///< classical bit arrays
  std::unordered_map<std::string, bool> bools_;                 ///< classical bools
  std::unordered_map<std::string, long long> ints_;             ///< classical ints
  std::mt19937_64 rng_;                                          ///< RNG for measurement
};

