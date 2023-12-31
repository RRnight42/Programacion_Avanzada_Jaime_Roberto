#include "Solid.h"
#include <iostream>
using namespace std;

void Solid::Update(const float& deltaTime , Vector3D gravity) {

	this->SetPosition(this->GetPosition() + this->GetSpeed() * deltaTime);
	this->SetRotation(this->GetRotation() + this->GetRotationSpeed() * deltaTime);


	if (this->GetGravity()) {

		this->SetSpeed(Vector3D(this->GetSpeed() + gravity * deltaTime));

	}

};

bool Solid::CheckColission(Solid* other) {

	Vector3D diff = this->GetPosition() - other->GetPosition();
	return diff.Magnitude() < 0.75; 


};

/*
ostream& operator<<(ostream& o, Solid& s) {

	o << "Posicion :" << s.GetPosition();
	o << "Rotacion :" << s.GetRotation();
	
	
	// Y mas cosas para depurar
	return o;

}
*/