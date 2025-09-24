OPENQASM 3.0;
include "stdgates.inc";

qubit[2] phi;

h phi[0];
cx phi[0], phi[1];
