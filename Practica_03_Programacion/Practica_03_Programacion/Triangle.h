#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Triangle : public Solid 
{

private:


	Color vertexColor1; 
	Color vertexColor2;
	Color vertexColor3;

	Vector3D vertex1;
	Vector3D vertex2;
	Vector3D vertex3;

	Vector3D normal1;
	Vector3D normal2;
	Vector3D normal3;

public : 

	Triangle( Vector3D vertex1 = Vector3D(), 
		      Vector3D vertex2 = Vector3D(), 
		      Vector3D vertex3 = Vector3D(),
	          Vector3D normal1 = Vector3D(), 
		      Vector3D normal2 = Vector3D(), 
		      Vector3D normal3 = Vector3D(),
		      Color color1 = Color(1,1,1), 
		      Color color2 = Color(1,1,1), 
		      Color color3 = Color(1,1,1)
	         ) :
		      vertex1(vertex1), vertex2(vertex2) , vertex3(vertex3),
	          normal1(normal1) ,normal2(normal2) , normal3(normal3),
	          vertexColor1(color1) , vertexColor2(color2) , vertexColor3(color3) {}

	inline Vector3D GetVertex1() { return this->vertex1; }
	inline Vector3D GetVertex2() { return this->vertex2; }
	inline Vector3D GetVertex3() { return this->vertex3; }

	inline void SetVertex1(const Vector3D& vertexToSet) { this->vertex1 = vertexToSet; }
	inline void SetVertex2(const Vector3D& vertexToSet) { this->vertex2 = vertexToSet; }
	inline void SetVertex3(const Vector3D& vertexToSet) { this->vertex3 = vertexToSet; }

	inline Vector3D GetNormal1() { return this->normal1; }
	inline Vector3D GetNormal2() { return this->normal2; }
	inline Vector3D GetNormal3() { return this->normal3; }

	inline void SetNormal1(const Vector3D& normalToSet) { this->normal1 = normalToSet; }
	inline void SetNormal2(const Vector3D& normalToSet) { this->normal2 = normalToSet; }
	inline void SetNormal3(const Vector3D& normalToSet) { this->normal3 = normalToSet; }


	inline Color* GetColor1() { return &vertexColor1; }
	inline Color* GetColor2() { return &vertexColor2; }
	inline Color* GetColor3() { return &vertexColor3; }

	inline void SetColor1(const Color& ColorToSet) { this->vertexColor1 = ColorToSet; }
	inline void SetColor2(const Color& ColorToSet) { this->vertexColor2 = ColorToSet; }
	inline void SetColor3(const Color& ColorToSet) { this->vertexColor3 = ColorToSet; }

	void Render();

};

