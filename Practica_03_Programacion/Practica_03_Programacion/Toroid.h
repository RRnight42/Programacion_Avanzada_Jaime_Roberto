#pragma once
#include "Solid.h"
#include <GL/glut.h>
class Toroid : public Solid
{


private:

	float innerRadius;
	float outerRadius;
	int sides;
	int rings;





public:

	Toroid(float innerRadius = 0.75 , float outerRadius = 1 , int sides = 20 , int rings = 20 ) : Solid(), innerRadius(innerRadius), outerRadius(outerRadius), sides(sides), rings(rings) {}

	inline float GetInnerRadius() { return this->innerRadius; }
	inline float GetOuterRadius() { return this->outerRadius; }
	inline int GetSides() { return this->sides; }
	inline int GetRings() { return this->rings; }

	inline void SetInnerRadius(const float& InnerRadiusToSet) { this->innerRadius = InnerRadiusToSet; }
	inline void SetOuterRadius(const float& OuterRadiusToSet) { this->outerRadius = OuterRadiusToSet; }
	inline void SetSides(const int& SidesToSet) { this->sides = SidesToSet; }
	inline void SetRings(const int& RingsToSet) { this->rings = RingsToSet; }

	void Render();
};


