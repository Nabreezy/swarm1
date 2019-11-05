// Filename: cParticle.cpp

#include "cParticle.h"

cParticle::cParticle() {
	for (int d = 0; d <= DIMENTION; d++) {
        this->set_position(d, 0);
        this->set_best_position(d, 0);
        this->set_velocity(d, 0);
    }
}

cParticle::cParticle(const cParticle &particle) {
  for (int d = 0; d <= DIMENTION; d++) {
    this->set_position(d, particle.get_position(d));
    this->set_best_position(d, particle.get_position(d));
    this->set_velocity(d, particle.get_velocity(d));
  }
}

int cParticle::get_position(int index) const {
	return this->mX[index];
}

int* cParticle::get_position() const {
	int* out = new int[DIMENTION];
	for (int d = 0; d <= DIMENTION; d++) {
		out[d] = this->mX[d];
	}
	return out;
}

void cParticle::set_position(int index, int value)
{
	this->mX[index] = value;
}

int cParticle::get_best_position(int index) const
{
	return this->mP[index];
}

int* cParticle::get_best_position() const {
	int* out = new int[DIMENTION];
	for (int d = 0; d <= DIMENTION; d++) {
		out[d] = this->mP[d];
	}
	return out;
}

void cParticle::set_best_position(int index, int value)
{
	this->mP[index] = value;
}

float cParticle::get_velocity(int index) const
{
	return this->mV[index];
}

void cParticle::set_velocity(int index, float value)
{
	this->mV[index] = value;
}

void cParticle::update_position() {
  for (int d = 0; d < DIMENTION; d++) {
    this->set_position(d, (int)(this->get_position(d) + this->get_velocity(d)));
  }
}