#include "Model.h"

void Model::PaintColor(Color color)
{
	for (Triangle& triangle : this->TriangleCollection)
	{
		triangle.SetColor1(color);
		triangle.SetColor2(color);
		triangle.SetColor3(color);
	}
}

void Model::Render()
{
	glPushMatrix();
	glTranslatef(this->GetPosition().GetCoordinateX(), this->GetPosition().GetCoordinateY(), this->GetPosition().GetCoordinateZ());
	glColor3f(this->GetColor().GetRedComponent(), this->GetColor().GetGreenComponent(), this->GetColor().GetBlueComponent());
	glRotatef(this->GetRotation().GetCoordinateX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetRotation().GetCoordinateY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetRotation().GetCoordinateZ(), 0.0, 0.0, 1.0);

	for (Triangle& triangle : this->TriangleCollection)
	{
		triangle.Render();
	}

	glPopMatrix();
}

void Model::AddTriangle(Triangle triangle) {

  this->TriangleCollection.push_back(triangle); 
}

void Model :: Clear() { 
	this->TriangleCollection.clear(); 
}
