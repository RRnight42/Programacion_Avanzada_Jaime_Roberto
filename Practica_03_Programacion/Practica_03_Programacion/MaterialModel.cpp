#include "MaterialModel.h"
#include <iostream>

void MaterialModel::AddMaterialTriangle(MaterialTriangle triangle)
{
	this->triangles.push_back(triangle);
}

void MaterialModel::Clear() {


	this->triangles.clear();


}


void MaterialModel::Render()
{
	glPushMatrix();
	glTranslatef(GetPosition().GetCoordinateX(), GetPosition().GetCoordinateY(), GetPosition().GetCoordinateZ());
	glColor3f(GetColor().GetRedComponent(), GetColor().GetGreenComponent(), GetColor().GetBlueComponent());
	glRotatef(GetRotation().GetCoordinateX(), 1.0, 0.0, 0.0);
	glRotatef(GetRotation().GetCoordinateY(), 0.0, 1.0, 0.0);
	glRotatef(GetRotation().GetCoordinateZ(), 0.0, 0.0, 1.0);
	for (MaterialTriangle triangle : this->triangles)
	{
		triangle.Render();
	}
	glPopMatrix();
}