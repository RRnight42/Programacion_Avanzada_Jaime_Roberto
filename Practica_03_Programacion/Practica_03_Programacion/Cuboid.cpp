#include "Cuboid.h"
void Cuboid::Render() {

	glPushMatrix();
	glTranslatef(this->GetPosition().GetCoordinateX(), this->GetPosition().GetCoordinateY(), this->GetPosition().GetCoordinateZ());
	glColor3f(this->GetColor().GetRedComponent(), this->GetColor().GetGreenComponent(), this->GetColor().GetBlueComponent());
	glRotatef(this->GetRotation().GetCoordinateX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetRotation().GetCoordinateY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetRotation().GetCoordinateZ(), 0.0, 0.0, 1.0);
	glScalef(this->GetLength(), this->GetHeight(), this->GetWidth());
	glutSolidCube(1);
	glPopMatrix();
}