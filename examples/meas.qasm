OPENQASM 3.0;
include "stdgates.inc";

// example of measurement on 3-qubit GHZ state
qubit[3] phi;

h phi[0];
cx phi[0], phi[1];
cx phi[1], phi[2];

bit[3] r;

r[0] = measure phi[0];
r[1] = measure phi[1];
r[2] = measure phi[2];
