#pragma once

#include "Color.h"
#include <GL/glut.h>
#include "Vector3D.h"

class Solid
{

private:

	Color color;
	Vector3D position;
	Vector3D rotation;
	Vector3D rotationSpeed;
	Vector3D speed;
	bool transparent;
	bool UseGravity;

public:

	Solid(Vector3D position = Vector3D(0,0,0) ,
		  Color color = Color(1,1,1), 
		  Vector3D rotation = Vector3D(0,0,0), 
		  Vector3D rotationSpeed = Vector3D(0,0,0), 
		  Vector3D speed = Vector3D(0,0,0) , 
		  bool transparent = false , 
		  bool gravity = false) : position(position),
		color(color),
		rotation(rotation), 
		rotationSpeed(rotationSpeed), 
		speed(speed), 
		transparent(false) {}
	



	inline Color GetColor() { return  this->color; }
	inline Vector3D GetPosition() { return this->position; }
	inline Vector3D GetRotation() { return this->rotation; }
	inline Vector3D GetRotationSpeed() { return this->rotationSpeed; }
	inline Vector3D GetSpeed() { return this->speed; }
	inline const bool& GetTransparent() { return transparent; }
	inline const bool& GetGravity() { return UseGravity; }

	inline void SetColor(const Color& ColorToSet) { color = Color(ColorToSet); }
	inline void SetPosition(const Vector3D& PositionToSet) { position = Vector3D(PositionToSet); }
	inline void SetRotation(const Vector3D& RotationToSet) { rotation = Vector3D(RotationToSet); }
	inline void SetRotationSpeed(const Vector3D& RotationSpeedToSet) { rotationSpeed = Vector3D(RotationSpeedToSet); }
	inline void SetSpeed(const Vector3D& SpeedToSet) { speed = Vector3D(SpeedToSet); }
	inline void SetTransparent(const bool TransparentToSet) { transparent = TransparentToSet; }
	inline void SetGravity(const bool GravityToSet) { UseGravity = GravityToSet; }

	bool CheckColission(Solid* other);

	//friend ostream& operator<<(ostream& o, const Vector3D v);

	virtual void Render() = 0;
	virtual void Update(const float& deltaTime, Vector3D gravity);

};

