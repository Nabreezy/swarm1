#ifndef C_FUNCTIONS_H
#define C_FUNCTIONS_H
#include "swarm1.h"
int test(int X[DIMENTION]);
int f1(int X[DIMENTION]);    // Sphere
int f2(int X[DIMENTION]);    // Schwefel's 2.22
int f3(int X[DIMENTION]); // Schwefel's 1.20
int f4(int X[DIMENTION]); // Schwefel's 2.21
int f5(int X[DIMENTION]); // Rosenbrock
int f6(int X[DIMENTION]); // Step
int f7(int X[DIMENTION]); // Quartic Noise
int f8(int X[DIMENTION]);
int f9(int X[DIMENTION]);
int f10(int X[DIMENTION]); // Ackley
int f11(int X[DIMENTION]); // look's like Griewank
int f12(int X[DIMENTION]);
int f13(int X[DIMENTION]);
int f14(int X[DIMENTION]); // a not define
int f15(int X[DIMENTION]); // a, b not define
int u(int x, int a, int k, int m);
#endif