#include "Game.h" // aqui se incluye el archivo H con los metodos 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MaterialModelLoader.h"
using namespace std;

void Game::ProcessKeyPressed(unsigned char key, int px, int py) {
	
	scenes[1]->ProcessKeyPressed(key , px , py);

}

void Game::ProcessMouseClick(int button, int state, int x, int y) {

	cout << "Clic" << button << endl;

}
void Game::ProcessMouseMovement(int x, int y) {

	cout << "Mouse movement" << x << " , " << y << endl;

}
void Game::Init() {

	Scene* menuScene = new(nothrow) Scene();
	Scene* gameScene = new(nothrow) Scene();
	Scene* winScene = new (nothrow) Scene();
	Scene* loseScene = new (nothrow) Scene();

	
	this->scenes.push_back(menuScene);
	this->scenes.push_back(gameScene);
	this->scenes.push_back(winScene);
	this->scenes.push_back(loseScene);

	this->activeScene = menuScene;

	MaterialModelLoader* loader = new MaterialModelLoader();

}

void Game::Update() {

	if (activeScene->IsOver()) {
	
		this->activeScene = scenes[2];
	
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