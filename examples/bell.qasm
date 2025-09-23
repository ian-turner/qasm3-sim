OPENQASM 3.0;
include "stdgates.inc";

qubit a;
qubit b;
bit[2] b;

h a;
cx a, b;

b[0] = measure a;
b[1] = measure b;
