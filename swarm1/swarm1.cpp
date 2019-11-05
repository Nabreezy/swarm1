// swarm1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "swarm1.h"
#include "functions.h"

cParticle particles[MAX_PARTICLES];
int (*f)(int x[DIMENTION]) = f2;
// bool comp(int a, int b) { return a < b; } // minimum
// bool comp(int a, int b) { return a > b; } // maximum
bool comp(int a, int b) { return abs(TARGET - a) < abs(TARGET - b); } // point convergence

int main() {
	srand((unsigned)time(0));
	psoAlgorithm();
	return 0;
}



void psoAlgorithm() {
	int *g = new int[DIMENTION];
	int gBestTest = 0;
	int epoch = 0;
	bool done = false;

  	// init

	for (int d = 0; d < DIMENTION; d++) {
        int x = g[d] = getRandomNumber(LOWER, UPPER);
	}

	for (int i = 0; i < MAX_PARTICLES; i++) {
		for (int d = 0; d < DIMENTION; d++) {
			int x = getRandomNumber(LOWER, UPPER);
			particles[i].set_position(d, x);
			particles[i].set_best_position(d, x);
		}

		if (comp(f(particles[i].get_position()), f(g))) {
			g = particles[i].get_position();
		}

		for (int d = 0; d < DIMENTION; d++) {
			int diff = abs(UPPER - LOWER);
			int v = getRandomNumber(-diff, diff);
			particles[i].set_velocity(d, (float)v);
		}
	}

	cout << "init completed." << endl;
	while (!done) {
		cout << epoch << endl;
		for (int i = 0; i < MAX_PARTICLES; i++) {
			cout << "f(";
			for (int d = 0; d < DIMENTION; d++) {
				
				if (d < DIMENTION - 1) {
					cout << particles[i].get_position(d) << ", ";
				} else {
					cout << particles[i].get_position(d) << "\b) = ";
				}
			
			}
			cout << f(particles[i].get_position()) << endl;
        }

		if (epoch > MAX_EPOCHS) {
			cout << epoch << " epochs completed." << endl;
			break;
		}
		epoch += 1;

		for (int i = 0; i < MAX_PARTICLES; i++) {
			for (int d = 0; d < DIMENTION; d++) {
				int x = particles[i].get_position(d);
				int p = particles[i].get_best_position(d);
				float v = particles[i].get_velocity(d);
				float rp = gRand(), rg = gRand();
				float w1 = 1, w2 = 1, w3 = 1;
				particles[i].set_velocity(
					d, w1 * v + w2 * rp * (p - x) + w3 * rg * (g[d] - x));
			}
			particles[i].update_position();

			if (comp(f(particles[i].get_position()), f(particles[i].get_best_position()))) {
				for (int d = 0; d <= DIMENTION; d++) {
					particles[i].set_best_position(d, particles[i].get_position(d));
				}

				if (comp(f(particles[i].get_best_position()), f(g))) {
					g = particles[i].get_best_position();
				}
			}
		}

		
	}

    cout << "f(";
    for (int d = 0; d < DIMENTION; d++) {
    	if (d < DIMENTION - 1) {
		cout << g[d] << ", ";
		} else {
		cout << g[d] << "\b) = ";
		}
	}
	cout << f(g) << endl;

}

float gRand() {
	// Returns a pseudo-random float between 0.0 and 1.0
	return float(rand() / (RAND_MAX + 1.0));
}

int getRandomNumber(int low, int high) {
	// Returns a pseudo-random integer between low and high.
	return low + int(((high - low) + 1) * rand() / (RAND_MAX + 1.0));
}