#include "Vector3D.h"
#include <iostream>;
#include <cstdlib>;
#include <ctime>;


// constructor copia

Vector3D::Vector3D(const Vector3D& obj) {

	this->coordinateX = obj.coordinateX;
	this->coordinateY = obj.coordinateY;
	this->coordinateZ = obj.coordinateZ;

}


Vector3D Vector3D::Add(const Vector3D& vector) {



	Vector3D newVector(this->GetCoordinateX() + vector.GetCoordinateX(), this->GetCoordinateY() + vector.GetCoordinateY(), this->GetCoordinateZ() + vector.GetCoordinateZ());
	return newVector;
}

Vector3D Vector3D::Substract(const Vector3D& vector) {



	Vector3D newVector(this->GetCoordinateX() - vector.GetCoordinateX(), this->GetCoordinateY() - vector.GetCoordinateY(), this->GetCoordinateZ() - vector.GetCoordinateZ());
	return newVector;
}

Vector3D Vector3D::Product(const float value) {



	Vector3D newVector(this->GetCoordinateX() * value, this->GetCoordinateY() * value, this->GetCoordinateZ() * value);
	return newVector;
}

Vector3D Vector3D::Division(const float value) {


	Vector3D newVector(this->GetCoordinateX() / value, this->GetCoordinateY() / value, this->GetCoordinateZ() / value);
	return newVector;
}


float Vector3D::DotProduct(const Vector3D& vector) {

	float value = this->GetCoordinateX() * vector.GetCoordinateX() + this->GetCoordinateY() * vector.GetCoordinateY() + this->GetCoordinateZ() + vector.GetCoordinateZ();

	return value;

}

float Vector3D::Magnitude() {

	float magnitude = sqrt(pow(this->GetCoordinateX(), 2) + pow(this->GetCoordinateY(), 2) + pow(this->GetCoordinateZ(), 2));
	return magnitude;
}

Vector3D Vector3D :: operator+(const Vector3D& vector) {

	float x = this->GetCoordinateX() + vector.GetCoordinateX();
	float y = this->GetCoordinateY() + vector.GetCoordinateY();
	float z = this->GetCoordinateZ() + vector.GetCoordinateZ();

	return Vector3D(x, y, z);

}
Vector3D Vector3D :: operator-(const Vector3D& vector) {

	float x = this->GetCoordinateX() - vector.GetCoordinateX();
	float y = this->GetCoordinateY() - vector.GetCoordinateY();
	float z = this->GetCoordinateZ() - vector.GetCoordinateZ();

	return Vector3D(x, y, z);
}
Vector3D Vector3D :: operator*(const float value) {

	float x = this->GetCoordinateX() * value;
	float y = this->GetCoordinateY() * value;
	float z = this->GetCoordinateZ() * value;

	return Vector3D(x, y, z);
}

Vector3D Vector3D::operator/(const float value)
{
	return Vector3D(this->GetCoordinateX() / value, this->GetCoordinateY() / value, this->GetCoordinateZ() / value);
}

float Vector3D::operator*(const Vector3D& vector)
{
	float x = this->GetCoordinateX() * vector.GetCoordinateX();
	float y = this->GetCoordinateY() * vector.GetCoordinateY();
	float z = this->GetCoordinateZ() * vector.GetCoordinateZ();

	return (x + y + z);
}

float& Vector3D :: operator[](const int& axis) {

	if (axis > 2 || axis < 0) {
		throw out_of_range("Axis no encontrado");
	}

	if (axis == 0) return coordinateX;
	if (axis == 1) return coordinateY;
	if (axis == 2) return coordinateZ;


};

ostream& operator<<(ostream& o, Vector3D& v) {

	o << v.GetCoordinateX() << "," << v.GetCoordinateY() << "," << v.GetCoordinateZ();
	return o;

}