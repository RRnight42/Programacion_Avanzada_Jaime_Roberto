#pragma once

#include <vector>
#include "Solid.h"
#include "Model.h"
#include "ModelLoader.h"
#include "Camera.h"

using namespace std;

class Scene
{

private:


	vector<Solid*> gameObjects;

	Camera camera1;

	Vector3D boundary;
	Vector3D gravity ;

	bool ended;

	void CheckBoundary();
	
	int eliminatedAsteroids;
	

public:

	Scene(int eliminatedAsteroids = 0 , bool ended = true) : gameObjects(), camera1(Camera(Vector3D(0, 0, 12))), boundary(Vector3D(8, 6, 4)) , gravity(Vector3D(0, 9.8, 0)) , eliminatedAsteroids(eliminatedAsteroids), ended(ended) {}

	inline void AddGameObject(Solid* GameObject) { gameObjects.push_back(GameObject); }

	inline vector<Solid*> GetGameObjects() { return this->gameObjects; }
	inline Camera GetCamera() { return this->camera1; }
	inline Vector3D GetBoundary() { return this->boundary; }


	inline void SetBoundary(const Vector3D& BoundaryToSet) { this->boundary = BoundaryToSet; }

	void Init();
	void Render();
	void Update(const float& time);
	void ProcessKeyPressed(unsigned char key, int px, int py);
	

	bool IsOver();

};

