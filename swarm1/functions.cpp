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

int f3(cParticle particle) { //Schwefel's 2.21
  int total = 0;

  for (int i = 0; i < MAX_INPUTS; i++) {
    int t = 0;
    for (int j = 0; j < i; j++) {
      int x = particle.getData(j);
      t += x;
    }
    total += t*t
  }
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
    int y1 = particle.getData(i+1);
    sum1 += ((y - 1) * (y - 1)) * (1 + 10 * pow(sin(M_PI * y1), 2));
  }

  for (int i = 0; i < MAX_INPUTS; i++) {
    int x = particle.getData(i);
    sum2 += u(x, 10, 100, 4);
  }

  int n = MAX_INPUTS;
  int y1 = particle.getData(0);
  int yn = particle.getData(MAX_INPUTS - 1);
  double total = (M_PI/n) * (10*pow(sin(M_PI*y1), 2) + sum1 + pow(yn-1,2)) + sum2;
  return (int)total;
}

int f13(cParticle particle) {
  double sum1 = 0;
  double sum2 = 0;

  for (int i = 0; i < MAX_INPUTS; i++) {
    int x = particle.getData(i);
    sum1 += pow(x - 1, 2) * (1 + pow(sin(3*M_PI*x + 1), 2));
    sum2 += u(x, 5, 100, 4);
  }

  int n = MAX_INPUTS;
  int x1 = particle.getData(0);
  int xn = particle.getData(MAX_INPUTS - 1);
  double total = 0.1 * (pow(sin(3 * M_PI * x1), 2) + sum1 +
                        pow(xn - 1, 2) * (1 + pow(sin(2 * M_PI * xn), 2))) +
                 sum2;
  return (int)total;
}

int f14(cParticle particle) {
  int a[25][2];

  double total = (1 / 500);
  for (int j = 0; j < 25; j++) {
    double t = 0;
    for (int i = 0; i < 2; i++) {
      int x = particle.getData(i);
      t += pow(x - a[j][i],6);
    }
    total += 1/(j+t);
  }

  total = pow(total, -1);
  return (int)total;
}

int f15(cParticle particle) {
  int a[11];
  int b[11];

  double total = 0;
  for (int i = 0; i < 11; i++) {
      int x1 = particle.getData(0);
      int x2 = particle.getData(1);
      int x3 = particle.getData(2);
      int x4 = particle.getData(3);
      total += a[i] - (x1 * (pow(b[i], 2) + b[i] * x2)) /
                          (pow(b[i], 2) + b[i] * x3 + x4);
  }

  total = pow(total, 2);
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