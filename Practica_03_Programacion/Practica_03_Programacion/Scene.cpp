#include "Scene.h"
#include <iostream>

using namespace std;

void Scene::ProcessKeyPressed(unsigned char key, int px, int py) {
	
	if (key == 'd') {
	
		//gameObjects[0]->SetPosition(gameObjects[0]->GetPosition().GetCoordinateX() + 5);

	
	}
	if (key == 'a') {
	
	
		//gameObjects[0]->SetPosition(gameObjects[0]->GetPosition().GetCoordinateX() - 5);
	
	}

	if (key == 'x') {
	     


	     
	
	}
}


void Scene::Init() {


}

bool Scene::IsOver() {

	if (eliminatedAsteroids == 50) {

		return true;
	}
	else {
	
	
		return false;
	}

	
}



void Scene::Render() {

	camera1.Render();

	for (int i = 0; i < this->gameObjects.size(); i++) {

		gameObjects[i]->Render();


	}
}


void Scene::CheckBoundary() {

	for (int i = 0; i < this->gameObjects.size(); i++) {

		if (gameObjects[i]->GetPosition().GetCoordinateX() > boundary.GetCoordinateX() ||
			gameObjects[i]->GetPosition().GetCoordinateX() < -1 * boundary.GetCoordinateX()) {

			Vector3D newSpeed((gameObjects[i]->GetSpeed()));
			newSpeed.SetCoordinateX(-newSpeed.GetCoordinateX());
			gameObjects[i]->SetSpeed(newSpeed);
		}

		if (gameObjects[i]->GetPosition().GetCoordinateY() > boundary.GetCoordinateY() ||
			gameObjects[i]->GetPosition().GetCoordinateY() < -1 * boundary.GetCoordinateY()) {

			Vector3D newSpeed((gameObjects[i]->GetSpeed()));
			newSpeed.SetCoordinateY(-newSpeed.GetCoordinateY());
			gameObjects[i]->SetSpeed( newSpeed);
		}
		if (gameObjects[i]->GetPosition().GetCoordinateZ() > boundary.GetCoordinateZ() ||
			gameObjects[i]->GetPosition().GetCoordinateZ() < -1 * boundary.GetCoordinateZ()) {

			Vector3D newSpeed((gameObjects[i]->GetSpeed()));
			newSpeed.SetCoordinateZ(-newSpeed.GetCoordinateZ());
			gameObjects[i]->SetSpeed(newSpeed);
		}
	}

}




void Scene::Update(const float& time) {
	
	
	for (int i = 0; i < this->gameObjects.size(); i++) {

	
		gameObjects[i]->Update(time , this->gravity );

	}

	CheckBoundary();
	
}


