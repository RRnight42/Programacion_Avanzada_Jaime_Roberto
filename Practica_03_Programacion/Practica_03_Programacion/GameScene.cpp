#include "GameScene.h"
#include "MaterialModelLoader.h"










void GameScene::ProcessKeyPressed(unsigned char key, int px, int py) {

	if (key == 'd') {

		gameObjects[0]->SetPosition(gameObjects[0]->GetPosition().GetCoordinateX() + 5);


	}
	if (key == 'a') {


		gameObjects[0]->SetPosition(gameObjects[0]->GetPosition().GetCoordinateX() - 5);

	}

	if (key == 's') {

		MaterialModelLoader* loader = new MaterialModelLoader();
		MaterialModel* bullet = new MaterialModel("bullet");
		bullet->SetRotationSpeed(Vector3D(0 , 0 , 30));
		bullet->SetSpeed(Vector3D(0 , 3 , 0));
		gameObjects.push_back(bullet);
	}
}