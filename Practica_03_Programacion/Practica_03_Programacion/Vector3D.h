#pragma once
#include <iostream>

using namespace std;

class Vector3D
{



private:


	float coordinateX;
	float coordinateY;
	float coordinateZ;



public:

	// constructor copia

	Vector3D(const Vector3D& vector);

	// Operaciones con vectores
	Vector3D Add(const Vector3D& vectorToAdd);
	Vector3D Substract(const Vector3D& vectorToSubstract);
	Vector3D Product(const float value);
	Vector3D Division(const float value);
	float DotProduct(const Vector3D& vectorToProduct);
	float Magnitude();

	// sobrecargas 
	Vector3D operator+(const Vector3D& vector);
	Vector3D operator-(const Vector3D& vector);
	Vector3D operator*(const float value);
	Vector3D operator/(const float value);
	float operator*(const Vector3D& vector);
	//friend ostream& operator<<(ostream& o , const Vector3D v);

	float& operator[](const int& axis);

	Vector3D(float x = 0, float y = 0, float z = 0) : coordinateX(x), coordinateY(y), coordinateZ(z) {}


	inline float GetCoordinateX() const { return this->coordinateX; }
	inline float GetCoordinateY() const { return this->coordinateY; }
	inline float GetCoordinateZ() const { return this->coordinateZ; }



	inline void SetCoordinateX(const float& coordinateXToSet) { this->coordinateX = coordinateXToSet; }
	inline void SetCoordinateY(const float& coordinateYToSet) { this->coordinateY = coordinateYToSet; }
	inline void SetCoordinateZ(const float& coordinateZToSet) { this->coordinateZ = coordinateZToSet; }


};