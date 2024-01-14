#include "Game.h" 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MaterialModelLoader.h"
using namespace std;

void Game::ProcessKeyPressed(unsigned char key, int px, int py) {
	MaterialModelLoader* loader = new MaterialModelLoader();
	if (activeScene == scenes.at(1)) {
		
		if (key == 'd') {

			activeScene->GetGameObjects().at(0)->SetPosition(Vector3D(activeScene->GetGameObjects().at(0)->GetPosition().GetCoordinateX() + 0.5, activeScene->GetGameObjects().at(0)->GetPosition().GetCoordinateY(), activeScene->GetGameObjects().at(0)->GetPosition().GetCoordinateZ()));


		}
		if (key == 'a') {


			activeScene->GetGameObjects().at(0)->SetPosition(Vector3D(activeScene->GetGameObjects().at(0)->GetPosition().GetCoordinateX() - 0.5, activeScene->GetGameObjects().at(0)->GetPosition().GetCoordinateY(), activeScene->GetGameObjects().at(0)->GetPosition().GetCoordinateZ()));

		}

		if (key == 's') {
			
			MaterialModel* bullet = new MaterialModel();
			loader->LoadModel("bullet.obj");
			loader->SetScale(0.03);
			*bullet = loader->GetMaterialModel();
			bullet->SetRotationSpeed(Vector3D(0 , 0 , -15));
			bullet->SetPosition(Vector3D(activeScene->GetGameObjects().at(0)->GetPosition().GetCoordinateX() , activeScene->GetGameObjects().at(0)->GetPosition().GetCoordinateY() + 2 , activeScene->GetGameObjects().at(0)->GetPosition().GetCoordinateZ()));
			bullet->SetSpeed(Vector3D(0 , 0.6 , 0));
			activeScene->AddGameObject(bullet);
		}
	}



	if (activeScene == scenes.at(2) || activeScene == scenes.at(3)) {
	
		if (key == 'r') {
		
			this->activeScene = scenes.at(0);


		}
	
	}
}

void Game::ProcessMouseMovement(int x, int y) { cout << "Mouse movement" << x << " , " << y << endl; }
void Game::ProcessMouseClick(int button, int state, int x, int y) {

	if (activeScene == scenes.at(0)) {
	
	
	
		this->activeScene = scenes.at(1);
	
	
	}



}

void Game::Init() {

	Scene* menuScene = new(nothrow) Scene();
	Scene* gameScene = new(nothrow) Scene();
	Scene* winScene = new(nothrow) Scene();
	Scene* loseScene = new(nothrow) Scene();

	this->scenes.push_back(menuScene);
	this->scenes.push_back(gameScene);
	this->scenes.push_back(winScene);
	this->scenes.push_back(loseScene);

	this->activeScene = gameScene;

	MaterialModelLoader* loader = new MaterialModelLoader();

	////////MENU///////////
	MaterialModel* spaceship_menu = new MaterialModel();
	loader->LoadModel("nave.obj");
	loader->SetScale(0.3);
	*spaceship_menu = loader->GetMaterialModel();
	spaceship_menu->SetPosition(Vector3D(1, 0, -10));
	spaceship_menu->SetRotation(Vector3D(30, -30, 0));
	spaceship_menu->SetRotationSpeed(Vector3D(0, -0.3, 0));

	menuScene->AddGameObject(spaceship_menu);
	loader->Clear();

	Text* title = new Text("Meteor impact");
	Text* instructions = new Text("AD : moverse izquierda/derecha. S : disparar misil.");
	Text* start = new Text("Clic en el raton para empezar");

	title->SetPosition(Vector3D(-0.14, 0.35, -1));
	instructions->SetPosition(Vector3D(-0.2, -0.55, -1));
	start->SetPosition(Vector3D(-0.3, -0.23, -1));
	menuScene->AddGameObject(title);
	menuScene->AddGameObject(instructions);
	menuScene->AddGameObject(start);


	////////GAME///////////

	MaterialModelLoader* loader2 = new MaterialModelLoader();

	MaterialModel* nave_player = new MaterialModel();
	loader2->SetScale(0.5);
	loader2->LoadModel("nave.obj");
	*nave_player = loader2->GetMaterialModel();
	nave_player->SetPosition(Vector3D(0, -25, -60));
	nave_player->SetRotation(Vector3D(90, 180, 0));
	gameScene->AddGameObject(nave_player);
	loader2->Clear();


	Text* score = new Text("Asteroides destruidos :" + eliminatedAsteroids);
	Text* remainingLives = new Text("Vidas restantes : " + lives);
	score->SetPosition(Vector3D(-0.7, 0.5, -1));
	remainingLives->SetPosition(Vector3D(0.5, 0.4, -1));
	gameScene->AddGameObject(score);
	gameScene->AddGameObject(remainingLives);


	for (int i = 0; i < 20; i++) {
		MaterialModelLoader* loader3 = new MaterialModelLoader();
		loader3->SetScale(1);
		loader3->LoadModel("asteroid.obj");
		MaterialModel* asteroid = new MaterialModel();
		*asteroid = loader3->GetMaterialModel();
		asteroid->SetTag("asteroid");
		asteroid->SetRotation(Vector3D(90 , 0 ,0));
		asteroid->SetRotationSpeed(Vector3D(0 , getRand(-0.4, 0.4) , 0));
		asteroid->SetSpeed(	Vector3D(0 , getRand(-0.1, -0.3) , 0));
		asteroid->SetPosition(Vector3D(getRand(-30, 30), getRand(40, 80), -60));
		gameScene->AddGameObject(asteroid);

	}

		////////WIN///////////
		MaterialModelLoader* loader3 = new MaterialModelLoader();
		Text* winText = new Text("Felicidades , superaste el nivel");
		Text* winText1 = new Text("Pulsa R para volver al menu");
		loader3->SetScale(0.02);
		loader3->LoadModel("nave.obj");

		MaterialModel* naveWin = new MaterialModel();
		
		*naveWin = loader->GetMaterialModel();

		naveWin->SetPosition(Vector3D(0,0,-3));
		naveWin->SetRotation(Vector3D(15, 180, 0));
		naveWin->SetSpeed(Vector3D(0,0.2,-1));
		winText->SetPosition(Vector3D(-0.3,0.15,-1));
		winText1->SetPosition(Vector3D(-0.3, -0.3, -1));
		winScene->AddGameObject(winText);
		winScene->AddGameObject(winText1);
		winScene->AddGameObject(naveWin);

		////////LOSE///////////
		MaterialModelLoader* loader4 = new MaterialModelLoader();
		Text* loseText = new Text("Vaya , la nave se destruyó...");
		Text* loseText1 = new Text("Pulsa R para volver al menú");
		loseText->SetPosition(Vector3D(0, 0, -1));
		loseText1->SetPosition(Vector3D(0, 0, -1));
		MaterialModel* asteroid1 = new MaterialModel();
		MaterialModel* asteroid2 = new MaterialModel();
		MaterialModel* asteroid3 = new MaterialModel();
		loader4->LoadModel("asteroid.obj");
		loader4->SetScale(0.2);
		*asteroid1 = loader4->GetMaterialModel();
		*asteroid2 = loader4->GetMaterialModel();
		*asteroid3 = loader4->GetMaterialModel();

		asteroid1->SetPosition(Vector3D(-7, 7, -20));
		asteroid2->SetPosition(Vector3D(0, -7, -20));
		asteroid3->SetPosition(Vector3D(9 ,6 , -20));

		asteroid1->SetRotation(Vector3D(90, 0, 0));
		asteroid2->SetRotation(Vector3D(90, 0, 0));
		asteroid3->SetRotation(Vector3D(90, 0, 0));

		asteroid1->SetRotationSpeed(Vector3D(0, getRand(-0.4, 0.4), 0));
		asteroid2->SetRotationSpeed(Vector3D(0, getRand(-0.4, 0.4), 0));
		asteroid3->SetRotationSpeed(Vector3D(0, getRand(-0.4, 0.4), 0));

		loseScene->AddGameObject(asteroid1);
		loseScene->AddGameObject(asteroid2);
		loseScene->AddGameObject(asteroid3);
		loseScene->AddGameObject(loseText);
		loseScene->AddGameObject(loseText1);
		loader4->Clear();

	}

bool Game::IsOver() {

	if (eliminatedAsteroids >= 30) {
	
	
		return true;
	
	}
	else {
	
	
		return false;
	
	}



}


bool Game::ShipLeaving() {

	if (activeScene == scenes.at(2)) {
	
	
		if (activeScene->GetGameObjects().at(0)->GetPosition().GetCoordinateZ() > 100)
		      { return true; }
		else  { return false;}
		
			
	
	}

}

bool Game::Death() {

	if (lives <= 0) {

		return true;
	}
	else {

		return false;
	}
}

void Game::LoseLive() {

	if (activeScene == scenes.at(1)) {


		for (int i = 0; i < activeScene->GetGameObjects().size(); i++) {
			if (activeScene->GetGameObjects().at(i)->GetTag() == "asteroid") {
				
				if (activeScene->GetGameObjects().at(0)->CheckColission(activeScene->GetGameObjects().at(i))) {
				
					lives -= 1;
					delete activeScene->GetGameObjects().at(i);
					activeScene->GetGameObjects().erase(activeScene->GetGameObjects().begin() + i);
					
				}
			}
		}
     }


}


void Game::ResetAsteroids() {


	for (int i = 0; i < scenes.at(1)->GetGameObjects().size(); i++) {
	
	
		if (scenes.at(1)->GetGameObjects().at(i)) {
		
		
		
		
		
		}
	
	
	}



}


void Game::DestroyAsteroids() {









}

void Game::Update() {

	LoseLive();


	if (ShipLeaving()) {
	
		if (activeScene == scenes.at(2)) {
			activeScene->GetGameObjects().erase(activeScene->GetGameObjects().begin());
		}
	}

	

	if (IsOver()) {
	
		this->activeScene = scenes.at(2);
	
	}

	if (Death()) {


		this->activeScene = scenes.at(3);
	}

	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if (currentTime.count() - this->initialMilliseconds.count() - this->lastUpdatedTime > UPDATE_PERIOD) {

     this->activeScene->Update(TIME_INCREMENT);
	 this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();

	}


	
}

void Game::Render() {

	if (this->activeScene != nullptr) { 		
		this->activeScene->Render(); 
	};
}