#pragma once
#include <vector>
#include <complex>
#include <unordered_map>
#include <random>
#include <string>
#include <stdexcept>
#include <cmath>
#include <cassert>

class Runtime {
  using cplx = std::complex<double>;
public:
  Runtime() : rng_(std::random_device{}()) {}

  void dumpState(std::ostream& out, double eps = 1e-12) const {
  out << "== Statevector (" << numQubits_ << " qubits) ==\n";
  for (size_t i = 0; i < psi_.size(); ++i) {
    double p = std::norm(psi_[i]);
    if (p > eps) {
      out << i << ": " << psi_[i] << "    |amp|^2=" << p << "\n";
    }
  }
}


  // ----- Quantum allocation -----
  void allocQubits(const std::string& name, int n) {
    if (n <= 0) throw std::runtime_error("allocQubits: size must be > 0");
    if (qregs_.count(name)) throw std::runtime_error("qubit register '" + name + "' already exists");
    int base = numQubits_;
    qregs_[name] = {base, n};
    numQubits_ += n;

    const size_t oldSize = psi_.size();
    const size_t newSize = size_t{1} << numQubits_;
    if (oldSize == 0) {
      psi_.assign(newSize, cplx{0,0});
      psi_[0] = cplx{1,0};
    } else {
      // Extend |ψ> by |0...0> on new wires.
      std::vector<cplx> newpsi(newSize, cplx{0,0});
      for (size_t i = 0; i < oldSize; ++i) newpsi[i] = psi_[i];
      psi_.swap(newpsi);
    }
  }

  // Resolve q[i] to the absolute wire index
  int qubitIndex(const std::string& qname, int idx) const {
    auto it = qregs_.find(qname);
    if (it == qregs_.end()) throw std::runtime_error("unknown qubit register '" + qname + "'");
    if (idx < 0 || idx >= it->second.size) throw std::runtime_error("qubit index out of range");
    return it->second.base + idx;
  }

  // ----- Classical storage -----
  void declareBits(const std::string& name, int n) {
    if (bits_.count(name) || ints_.count(name) || bools_.count(name))
      throw std::runtime_error("duplicate classical identifier '" + name + "'");
    bits_[name] = std::vector<int>(n, 0);
  }
  void declareBool(const std::string& name) {
    if (bits_.count(name) || ints_.count(name) || bools_.count(name))
      throw std::runtime_error("duplicate classical identifier '" + name + "'");
    bools_[name] = false;
  }
  void declareInt(const std::string& name, long long v = 0) {
    if (bits_.count(name) || ints_.count(name) || bools_.count(name))
      throw std::runtime_error("duplicate classical identifier '" + name + "'");
    ints_[name] = v;
  }

  // convenience setters/getters used by the visitor
  void setBit(const std::string& name, int i, int v) {
    auto it = bits_.find(name); if (it == bits_.end()) throw std::runtime_error("unknown bit var '"+name+"'");
    if (i < 0 || i >= (int)it->second.size()) throw std::runtime_error("bit index out of range");
    it->second[i] = (v != 0);
  }
  int  getBit(const std::string& name, int i) const {
    auto it = bits_.find(name); if (it == bits_.end()) throw std::runtime_error("unknown bit var '"+name+"'");
    if (i < 0 || i >= (int)it->second.size()) throw std::runtime_error("bit index out of range");
    return it->second[i];
  }
  void setBool(const std::string& name, bool v) { bools_.at(name) = v; }
  bool getBool(const std::string& name) const { return bools_.at(name); }
  void setInt(const std::string& name, long long v) { ints_.at(name) = v; }
  long long getInt(const std::string& name) const { return ints_.at(name); }

  bool hasBit(const std::string& n) const { return bits_.count(n); }
  bool hasBool(const std::string& n) const { return bools_.count(n); }
  bool hasInt(const std::string& n) const { return ints_.count(n); }

  // ----- Quantum ops -----
  void x(int q) {
    const size_t N = psi_.size();
    const size_t m = size_t{1} << q;
    for (size_t i = 0; i < N; i += (m << 1))
      for (size_t j = 0; j < m; ++j)
        std::swap(psi_[i + j], psi_[i + j + m]);
  }
  void h(int q) {
    static const double invsqrt2 = 1.0/std::sqrt(2.0);
    const size_t N = psi_.size();
    const size_t m = size_t{1} << q;
    for (size_t i = 0; i < N; i += (m << 1)) {
      for (size_t j = 0; j < m; ++j) {
        auto a = psi_[i + j];
        auto b = psi_[i + j + m];
        psi_[i + j]     = (a + b) * invsqrt2;
        psi_[i + j + m] = (a - b) * invsqrt2;
      }
    }
  }
  void cx(int c, int t) {
    if (c == t) throw std::runtime_error("control and target must differ");
    const size_t N = psi_.size();
    const size_t cm = size_t{1} << c;
    const size_t tm = size_t{1} << t;
    for (size_t i = 0; i < N; ++i) {
      if ((i & cm) && !(i & tm)) {
        std::swap(psi_[i], psi_[i | tm]);
      }
    }
  }

  int measure(int q) {
    const size_t N = psi_.size();
    const size_t m = size_t{1} << q;
    long double p1 = 0.0L;
    for (size_t i = 0; i < N; ++i) if (i & m) {
      p1 += std::norm(psi_[i]);
    }
    std::bernoulli_distribution dist((double)p1);
    int r = dist(rng_) ? 1 : 0;

    long double norm = 0.0L;
    if (r == 0) {
      for (size_t i = 0; i < N; ++i) if (i & m) psi_[i] = cplx{0,0};
      for (size_t i = 0; i < N; ++i) norm += std::norm(psi_[i]);
    } else {
      for (size_t i = 0; i < N; ++i) if (!(i & m)) psi_[i] = cplx{0,0};
      for (size_t i = 0; i < N; ++i) norm += std::norm(psi_[i]);
    }
    double s = (norm > 0) ? 1.0/std::sqrt((double)norm) : 0.0;
    for (auto& a : psi_) a *= s;
    return r;
  }

  void reset(int q) {
    int r = measure(q);
    if (r == 1) x(q);
  }

  // For quick debugging
  int numQubits() const { return numQubits_; }
  const std::vector<cplx>& state() const { return psi_; }

  void apply1(int q,
            std::complex<double> u00, std::complex<double> u01,
            std::complex<double> u10, std::complex<double> u11) {
  const size_t N = psi_.size();
  const size_t m = size_t{1} << q;
  for (size_t i = 0; i < N; i += (m << 1)) {
    for (size_t j = 0; j < m; ++j) {
      auto a = psi_[i + j];
      auto b = psi_[i + j + m];
      psi_[i + j]     = u00 * a + u01 * b;
      psi_[i + j + m] = u10 * a + u11 * b;
    }
  }
}


private:
  struct QReg { int base; int size; };
  int numQubits_ = 0;
  std::vector<cplx> psi_;
  std::unordered_map<std::string, QReg> qregs_;
  std::unordered_map<std::string, std::vector<int>> bits_;
  std::unordered_map<std::string, bool> bools_;
  std::unordered_map<std::string, long long> ints_;
  std::mt19937_64 rng_;
};

