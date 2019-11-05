#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <math.h>

#include "functions.h"

int test(int X[DIMENTION]) {
  int total = 0;
  for (int i = 0; i <= DIMENTION - 1; i++) {
    total += X[i];
  }
  return total;
}

int f1(int X[DIMENTION]) {
    int total = 0;

    for (int i = 0; i < DIMENTION; i++) {
      int x = X[i];
      total += x*x;
    }  // i

    return total;
}

int f2(int X[DIMENTION]) {
  int sum = 0;
  int prod = 1;

  for (int i = 0; i < DIMENTION; i++) {
    int x = abs(X[i]);
    sum += x;
    prod *= x;
  }  // i

  return sum + prod;
}

int f3(int X[DIMENTION]) {  // Schwefel's 2.21
  int total = 0;

  for (int i = 0; i < DIMENTION; i++) {
    int t = 0;
    for (int j = 0; j < i; j++) {
      int x = X[j];
      t += x;
    }
    total += t * t;
  }
  return 0;
}

int f4(int X[DIMENTION]) {
  int max = 0;
  for (int i = 0; i < DIMENTION; i++) {
    int x = abs(X[i]);
    if (x > max) {
      max = x;
    }
  }
  return max;
}

int f5(int X[DIMENTION]) {
  int total = 0;
  for (int i = 0; i < DIMENTION - 1; i++) {
    int x = X[i];
    int x1 = X[i + 1];
    total += 100 * (x1 - x * x) * (x1 - x * x) + (x - 1) * (x - 1);
  }
  return total;
}

int f6(int X[DIMENTION]) {
  double total = 0;
  for (int i = 0; i < DIMENTION; i++) {
    int x = X[i];
    total += (x + 0.5) * (x + 0.5);
  }
  return (int)total;
}

int f7(int X[DIMENTION]) {
  double total = 0;
  for (int i = 0; i < DIMENTION; i++) {
    int x = X[i];
    total += i * pow(x, 4) + gRand();
  }
  return (int)total;
}

int f8(int X[DIMENTION]) {
  double total = 0;
  for (int i = 0; i < DIMENTION; i++) {
    int x = X[i];
    total += -x * sin(sqrt(abs(x)));
  }
  return (int)total;
}

int f9(int X[DIMENTION]) {
  double total = 0;
  for (int i = 0; i < DIMENTION; i++) {
    int x = X[i];
    total += (x * x) - 10 * cos(2 * M_PI * x) + 10;
  }
  return (int)total;
}

int f10(int X[DIMENTION]) {
  double sum1 = 0;
  double sum2 = 0;
  for (int i = 0; i < DIMENTION; i++) {
    int x = X[i];
    sum1 += x * x;
    sum2 += cos(2 * M_PI * x);
  }

  double n = DIMENTION;
  double total = -20 * exp(-0.2 * sqrt((1 / n) * sum1)) - exp((1 / n) * sum2) + 20 + M_E;
  return (int)total;
}

int f11(int X[DIMENTION]) {
  double sum = 0;
  double prod = 1;
  for (int i = 0; i < DIMENTION; i++) {
    int x = X[i];
    sum += x * x;
    prod *= cos(x/sqrt(i));
  }

  double total = 1 / 4000 * sum - prod + 1;
  return (int)total;
}

int f12(int X[DIMENTION]) {
  double sum1 = 0;
  double sum2 = 0;

  for (int i = 0; i < DIMENTION - 1; i++) {
    int y = X[i];
    int y1 = X[i+1];
    sum1 += ((y - 1) * (y - 1)) * (1 + 10 * pow(sin(M_PI * y1), 2));
  }

  for (int i = 0; i < DIMENTION; i++) {
    int x = X[i];
    sum2 += u(x, 10, 100, 4);
  }

  int n = DIMENTION;
  int y1 = X[0];
  int yn = X[DIMENTION - 1];
  double total = (M_PI/n) * (10*pow(sin(M_PI*y1), 2) + sum1 + pow(yn-1,2)) + sum2;
  return (int)total;
}

int f13(int X[DIMENTION]) {
  double sum1 = 0;
  double sum2 = 0;

  for (int i = 0; i < DIMENTION; i++) {
    int x = X[i];
    sum1 += pow(x - 1, 2) * (1 + pow(sin(3*M_PI*x + 1), 2));
    sum2 += u(x, 5, 100, 4);
  }

  int n = DIMENTION;
  int x1 = X[0];
  int xn = X[DIMENTION - 1];
  double total = 0.1 * (pow(sin(3 * M_PI * x1), 2) + sum1 +
                        pow(xn - 1, 2) * (1 + pow(sin(2 * M_PI * xn), 2))) +
                 sum2;
  return (int)total;
}

int f14(int X[DIMENTION]) {
  int a[25][2];

  double total = (1 / 500);
  for (int j = 0; j < 25; j++) {
    double t = 0;
    for (int i = 0; i < 2; i++) {
      int x = X[i];
      t += pow(x - a[j][i],6);
    }
    total += 1/(j+t);
  }

  total = pow(total, -1);
  return (int)total;
}

int f15(int X[DIMENTION]) {
  int a[11];
  int b[11];

  double total = 0;
  for (int i = 0; i < 11; i++) {
      int x1 = X[0];
      int x2 = X[1];
      int x3 = X[2];
      int x4 = X[3];
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