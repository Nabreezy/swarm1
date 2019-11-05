#pragma once
// Filename: swarm1.h

#ifndef SWARM1_H
#define SWARM1_H

/*
Sources:
Kennedy, J. and Eberhart, R. C. Particle swarm optimization.
	   Proc. IEEE int'l conf. on neural networks Vol. IV, pp. 1942-1948.
	   IEEE service center, Piscataway, NJ, 1995.
PSO Tutorial found at: http://www.swarmintelligence.org/tutorials.php
*/
#include <iostream>
#include <iomanip>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

const int TARGET = 1000;
const int DIMENTION = 10;           // Number of variables to be optimized
const int MAX_PARTICLES = 10;
const float V_MAX = 10.0;           //Maximum velocity change allowed.

const int MAX_EPOCHS = 100;
//The particles will be initialized with data randomly chosen within the range
//of these starting min and max values: 
const int LOWER = -100;
const int UPPER = +100;

#include "cParticle.h"
// #include "functions.h"



int     main();
void    psoAlgorithm();
void    get_velocity(int gBestIndex);
void    update_position(int gBestIndex);
void    initialize();
float   gRand();
int     getRandomNumber(int low, int high);
int     minimum();

#endif