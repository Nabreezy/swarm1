#ifndef C_FUNCTIONS_H
#define C_FUNCTIONS_H
#include "swarm1.h"
int test(cParticle particle);
int f1(cParticle particle); // Sphere
int f2(cParticle particle); // Schwefel's 2.22
int f3(cParticle particle); // Schwefel's 1.20
int f4(cParticle particle); // Schwefel's 2.21
int f5(cParticle particle); // Rosenbrock
int f6(cParticle particle); // Step
int f7(cParticle particle); // Quartic Noise
int f8(cParticle particle);
int f9(cParticle particle);
int f10(cParticle particle); // Ackley
int f11(cParticle particle); // look's like Griewank
int f12(cParticle particle);
int f13(cParticle particle);
int f14(cParticle particle); // a not define
int f15(cParticle particle); // a, b not define
int u(int x, int a, int k, int m);
#endif