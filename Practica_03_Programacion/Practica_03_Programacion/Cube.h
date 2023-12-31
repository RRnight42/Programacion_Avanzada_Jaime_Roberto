#pragma once
#include <GL/glut.h>
#include "Solid.h"


class Cube : public Solid
{
private:

	float size;



public:

	Cube( float size = 1 ) : Solid(), size(size) {}



	inline float GetSize() const { return this->size; }

	inline void SetSize(const float& SizeToSet) { this->size = SizeToSet; };


	void Render();
};