#pragma once
#include "Solid.h"
#include <GL/glut.h>

class Camera : public Solid
{
private:


public:


	Camera(Vector3D position = Vector3D()) : Solid(position) {}



	void Render();



};

