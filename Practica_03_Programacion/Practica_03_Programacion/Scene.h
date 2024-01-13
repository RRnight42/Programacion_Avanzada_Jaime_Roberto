#pragma once

#include <vector>
#include "Solid.h"
#include "Text.h"
#include "Model.h"
#include "ModelLoader.h"
#include "Camera.h"

using namespace std;

class Scene
{

protected:

	
	vector<Solid*> gameObjects;

	Camera camera;

	Vector3D gravity ;

	

	
public:

	Scene(Vector3D gravity = Vector3D()) : gameObjects(), camera(Camera(Vector3D(0, 0, 0))) , gravity(gravity) {}

	inline void AddGameObject(Solid* GameObject) { gameObjects.push_back(GameObject); }

	inline vector<Solid*> GetGameObjects() { return this->gameObjects; }
	inline Camera GetCamera() { return this->camera; }


	virtual void Init();
	void Render();
    void Update(const float& time);
	virtual void ProcessKeyPressed(unsigned char key, int px, int py);
	
	

};

