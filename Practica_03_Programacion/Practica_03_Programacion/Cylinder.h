#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Cylinder : public Solid
{


private:

	float baseRadius;
	float topRadius;
	float height;
	int slices;
	int slacks;




public:

	Cylinder( float baseRadius = 1, float topRadius = 1,float height = 3,int slices = 20, int slacks = 20) : Solid(), baseRadius(baseRadius), topRadius(topRadius), height(height), slices(slices), slacks(slacks) {}

	inline float GetBaseRadius() { return this->baseRadius; }
	inline float GetTopRadius() { return this->topRadius; }
	inline float GetHeight() { return this->height; }
	inline int GetSlices() { return this->slices; }
	inline int GetSlacks() { return this->slacks; }

	inline void SetBaseRadius(const float& BaseRadiusToSet) { this->baseRadius = BaseRadiusToSet; }
	inline void SetTopRadius(const float& TopRadiusToSet) { this->topRadius = TopRadiusToSet; }
	inline void SetHeight(const float& HeightToSet) { this->height = HeightToSet; }
	inline void SetSlices(const int& SlicesToSet) { this->slices = SlicesToSet; }
	inline void SetSlacks(const int& SlacksToSet) { this->slacks = SlacksToSet; }





	void Render();

};