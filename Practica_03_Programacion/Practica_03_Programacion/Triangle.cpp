#include "Triangle.h"

void Triangle  :: Render() {


	glBegin(GL_TRIANGLES);
	//vértice 1
	glColor3f( this->GetColor1()->GetRedComponent(), this->GetColor1()->GetGreenComponent(), this->GetColor1()->GetBlueComponent());
	glNormal3f(this->GetNormal1().GetCoordinateX(),this->GetNormal1().GetCoordinateY(), this->GetNormal1().GetCoordinateZ());
	glVertex3f(this->GetVertex1().GetCoordinateX(), this->GetVertex1().GetCoordinateY(), this->GetVertex1().GetCoordinateZ());
	//vértice 2
	glColor3f(this->GetColor2()->GetRedComponent(), this->GetColor2()->GetGreenComponent(), this->GetColor2()->GetBlueComponent());
	glNormal3f(this->GetNormal2().GetCoordinateX(), this->GetNormal2().GetCoordinateY(), this->GetNormal2().GetCoordinateZ());
	glVertex3f(this->GetVertex2().GetCoordinateX(), this->GetVertex2().GetCoordinateY(), this->GetVertex2().GetCoordinateZ());
	//vértice 3
	glColor3f(this->GetColor3()->GetRedComponent(), this->GetColor3()->GetGreenComponent(), this->GetColor3()->GetBlueComponent());
	glNormal3f(this->GetNormal3().GetCoordinateX(), this->GetNormal3().GetCoordinateY(), this->GetNormal3().GetCoordinateZ());
	glVertex3f(this->GetVertex3().GetCoordinateX(), this->GetVertex3().GetCoordinateY(), this->GetVertex3().GetCoordinateZ());
	glEnd();

	 
}