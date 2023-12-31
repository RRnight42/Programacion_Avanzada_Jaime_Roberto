#include "Text.h"

void Text::Render() {

	glPushMatrix();
	glColor3f( this->GetColor().GetRedComponent(), this->GetColor().GetGreenComponent(), this->GetColor().GetBlueComponent());
	glTranslatef(this->GetPosition().GetCoordinateX(), this->GetPosition().GetCoordinateY(), this->GetPosition().GetCoordinateZ());
	glRasterPos3d(0, 0, 0);
	for (char& c : texto) {

		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);

	
	}
		
	glPopMatrix();


}