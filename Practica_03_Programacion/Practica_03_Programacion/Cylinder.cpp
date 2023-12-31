#include "Cylinder.h"

void Cylinder::Render() {

	GLUquadricObj* quadricTemp = gluNewQuadric();

	glPushMatrix();
	glTranslatef(this->GetPosition().GetCoordinateX(), this->GetPosition().GetCoordinateY(), this->GetPosition().GetCoordinateZ());
	glColor3f(this->GetColor().GetRedComponent(), this->GetColor().GetGreenComponent(), this->GetColor().GetBlueComponent());
	glRotatef(this->GetRotation().GetCoordinateX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetRotation().GetCoordinateY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetRotation().GetCoordinateZ(), 0.0, 0.0, 1.0);
	glTranslatef(0, 0, -this->GetHeight() / 2);
	gluCylinder(quadricTemp, this->GetBaseRadius(), this->GetTopRadius(), this->GetHeight(), this->GetSlices(), this->GetSlacks());
	glPopMatrix();
	gluDeleteQuadric(quadricTemp);

}