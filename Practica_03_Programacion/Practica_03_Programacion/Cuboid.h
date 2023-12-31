#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Cuboid : public Solid
{
private:



	float length;
	float height;
	float width;



public:

	Cuboid(float length = 0.5 , float height = 0.5 , float width = 0.4) : Solid(), length(length), height(height), width(width) {}



	inline float GetLength() const { return this->length; }
	inline float GetHeight() const { return this->height; }
	inline float GetWidth() const { return this->width; }


	inline void SetLength(const float& LengthToSet) { this->length = LengthToSet; }
	inline void SetHeight(const float& HeightToSet) { this->height = HeightToSet; }
	inline void SetWidth(const float& WidthToSet) { this->width = WidthToSet; }


	void Render();
};
