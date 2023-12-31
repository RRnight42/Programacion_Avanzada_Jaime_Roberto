#pragma once
#include <GL/glut.h>
#include "Solid.h"



class Sphere : public Solid
{

private:


	float radio;
	int slices;
	int slacks;



public:

	Sphere( float radio = 0.4,int slices = 20,int slacks = 20) :Solid(), radio(radio), slices(slices), slacks(slices) {}



	inline float GetRadio() const { return this->radio; }
	inline int GetSlices() const { return this->slices; }
	inline int GetSlacks() const { return this->slacks; }


	inline void SetRadio(const float& RadioToSet) { this->radio = RadioToSet; }
	inline void SetSlices(const int& SlicesToSet) { this->slices = SlicesToSet; }
	inline void SetSlacks(const int& SlacksToSet) { this->slacks = SlacksToSet; };


	void Render();
};
