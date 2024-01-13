#include "Scene.h"
#include <iostream>

using namespace std;

void Scene::ProcessKeyPressed(unsigned char key, int px, int py) {

	if (key == 'd') {

		gameObjects[0]->SetPosition(gameObjects[0]->GetPosition().GetCoordinateX() + 5);


	}
	if (key == 'a') {


		gameObjects[0]->SetPosition(gameObjects[0]->GetPosition().GetCoordinateX() - 5);

	}

	if (key == 'x') {





	}


}


void Scene::Init() {}

void Scene::Render() {

	camera.Render();

	for (int i = 0; i < this->gameObjects.size(); i++) {

		gameObjects[i]->Render();


	}
}


void Scene::Update(const float& time) {
	
	
	for (int i = 0; i < this->gameObjects.size(); i++) {

	
		gameObjects[i]->Update(time , this->gravity );

	}	
}


