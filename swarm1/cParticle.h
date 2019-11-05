#pragma once
// Filename: cParticle.h

#ifndef C_PARTICLE_H
#define C_PARTICLE_H

#include "swarm1.h"

class cParticle
{

private:
	int     mX[DIMENTION];
	int     mP[DIMENTION];
	float   mV[DIMENTION];

public:
	cParticle();
    cParticle(const cParticle &particle);
    int get_position(int index) const;
    int* get_position() const;
    void set_position(int index, int value);
    int get_best_position(int index) const;
    int* get_best_position() const;
    void set_best_position(int index, int value);
    float get_velocity(int index) const;
    void set_velocity(int index, float value);
    void update_position();

}; // end cParticle class.

#endif