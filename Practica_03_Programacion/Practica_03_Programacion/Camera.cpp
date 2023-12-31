#include "Camera.h"

void Camera::Render() {

	glTranslatef(-1 * this->GetPosition().GetCoordinateX(), -1 * this->GetPosition().GetCoordinateY(), -1 * this->GetPosition().GetCoordinateZ());
	glRotatef(this->GetRotation().GetCoordinateX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetRotation().GetCoordinateY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetRotation().GetCoordinateZ(), 0.0, 0.0, 1.0);


}