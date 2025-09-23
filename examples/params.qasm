OPENQASM 3;
include "stdgates.inc";

qubit[5] q;
h q[0];
cx q[0], q[1];
ry(pi/3) q[2:4];
rz(0.5) q[{0,2,4}];
u(pi/2, pi/2, pi/2) q[3];

