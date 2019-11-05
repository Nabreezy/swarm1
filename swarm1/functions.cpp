#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <math.h>

#include "functions.h"

int test(cParticle particle) {
  int total = 0;
  for (int i = 0; i <= MAX_INPUTS - 1; i++) {
    total += particle.getData(i);
  }  // i
  return total;
}

int f1(cParticle particle) {
    int total = 0;

    for (int i = 0; i < MAX_INPUTS; i++) {
      int x = particle.getData(i);
      total += x*x;
    }  // i

    return total;
}

int f2(cParticle particle) {
  int sum = 0;
  int prod = 1;

  for (int i = 0; i < MAX_INPUTS; i++) {
    int x = abs(particle.getData(i));
    sum += x;
    prod *= x;
  }  // i

  return sum + prod;
}

int f3(cParticle particle) {
  // for (int i = 0; i < MAX_INPUTS; i++) {
  //   for (int j = 0; j < i; j++) {

  //   }
  return 0;
}

int f4(cParticle particle) {
  int max = 0;
  for (int i = 0; i < MAX_INPUTS; i++) {
    int x = abs(particle.getData(i));
    if (x > max) {
      max = x;
    }
  }
  return max;
}


int f5(cParticle particle) {
  int total = 0;
  for (int i = 0; i < MAX_INPUTS - 1; i++) {
    int x = particle.getData(i);
    int x1 = particle.getData(i + 1);
    total += 100 * (x1 - x * x) * (x1 - x * x) + (x - 1) * (x - 1);
  }
  return total;
}

int f6(cParticle particle) {
  double total = 0;
  for (int i = 0; i < MAX_INPUTS; i++) {
    int x = particle.getData(i);
    total += (x + 0.5) * (x + 0.5);
  }
  return (int)total;
}


int f7(cParticle particle) {
  double total = 0;
  for (int i = 0; i < MAX_INPUTS; i++) {
    int x = particle.getData(i);
    total += i * pow(x, 4) + gRand();
  }
  return (int)total;
}


int f8(cParticle particle) {
  double total = 0;
  for (int i = 0; i < MAX_INPUTS; i++) {
    int x = particle.getData(i);
    total += -x * sin(sqrt(abs(x)));
  }
  return (int)total;
}

int f9(cParticle particle) {
  double total = 0;
  for (int i = 0; i < MAX_INPUTS; i++) {
    int x = particle.getData(i);
    total += (x * x) - 10 * cos(2 * M_PI * x) + 10;
  }
  return (int)total;
}

int f10(cParticle particle) {
  double sum1 = 0;
  double sum2 = 0;
  for (int i = 0; i < MAX_INPUTS; i++) {
    int x = particle.getData(i);
    sum1 += x * x;
    sum2 += cos(2 * M_PI * x);
  }

  double n = MAX_INPUTS;
  double total = -20 * exp(-0.2 * sqrt((1 / n) * sum1)) - exp((1 / n) * sum2) + 20 + M_E;
  return (int)total;
}

int f11(cParticle particle) {
  double sum = 0;
  double prod = 1;
  for (int i = 0; i < MAX_INPUTS; i++) {
    int x = particle.getData(i);
    sum += x * x;
    prod *= cos(x/sqrt(i));
  }

  double total = 1 / 4000 * sum - prod + 1;
  return (int)total;
}


int f12(cParticle particle) {
  double sum1 = 0;
  double sum2 = 0;

  for (int i = 0; i < MAX_INPUTS - 1; i++) {
    int y = particle.getData(i);
    sum1 += (y - 1) * (y - 1);
  }

  for (int i = 0; i < MAX_INPUTS; i++) {
    int x = particle.getData(i);
    sum2 += u(x, 10, 100, 4);
  }

  double total = 1;
  return (int)total;
}

int u(int x, int a, int k, int m) {
  if (x > a) {
    return k * pow(x - a, m);
  } else if (x < -a) {
    return k * pow(-x - a, m);
  } else {
    return 0;
  }
}