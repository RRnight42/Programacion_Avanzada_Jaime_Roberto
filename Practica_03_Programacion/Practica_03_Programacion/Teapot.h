#pragma once
#include <GL/glut.h>
#include "Solid.h"


class Teapot : public Solid
{

private:


	float size;

public:

	Teapot() : Solid(Vector3D(0.0, 0.0, 0.0), Color(0.0, 0.0, 0.0), Vector3D(0.0, 0.0, 0.0), Vector3D(), Vector3D(), bool(true)), size(0.4) {}


	inline float GetSize() const { return this->size; }

	inline void SetSize(const float& SizeToSet) { this->size = SizeToSet; }


	void Render();
};