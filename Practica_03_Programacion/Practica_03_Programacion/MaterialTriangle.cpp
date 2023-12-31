#include "MaterialTriangle.h"


void MaterialTriangle::Render() {
	glDisable(GL_COLOR_MATERIAL);
	this->useMaterial();
	glBegin(GL_TRIANGLES);

	glNormal3f(this->GetNormal1().GetCoordinateX(), this->GetNormal1().GetCoordinateY(), this -> GetNormal1().GetCoordinateZ());
	glVertex3f(this->GetVertex1().GetCoordinateX(), this->GetVertex1().GetCoordinateY(), this -> GetVertex1().GetCoordinateZ());
	glNormal3f(this->GetNormal2().GetCoordinateX(), this->GetNormal2().GetCoordinateY(), this -> GetNormal2().GetCoordinateZ());
	glVertex3f(this->GetVertex2().GetCoordinateX(), this->GetVertex2().GetCoordinateY(), this -> GetVertex2().GetCoordinateZ());
	glNormal3f(this->GetNormal3().GetCoordinateX(), this->GetNormal3().GetCoordinateY(), this -> GetNormal3().GetCoordinateZ());
	glVertex3f(this->GetVertex3().GetCoordinateX(), this->GetVertex3().GetCoordinateY(), this -> GetVertex3().GetCoordinateZ());
	glEnd();
}
void MaterialTriangle::useMaterial()
{
	float MatAmbient[] = { this->material.GetAmbientColor().GetRedComponent(), this -> material.GetAmbientColor().GetGreenComponent(), this->material.GetAmbientColor().GetBlueComponent(), 1.0f };
	float MatDiffuse[] = { this->material.GetDiffuseColor().GetRedComponent(), this -> material.GetDiffuseColor().GetGreenComponent(), this->material.GetDiffuseColor().GetBlueComponent(), 1.0f };
	float MatSpecular[] = { this->material.GetSpecularColor().GetRedComponent(), this -> material.GetSpecularColor().GetGreenComponent(), this->material.GetSpecularColor().GetBlueComponent(), 0.1f };
	float MatShininess = 60;
	float black[] = { 0.0f,0.0f,0.0f,1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MatAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, black);
}
