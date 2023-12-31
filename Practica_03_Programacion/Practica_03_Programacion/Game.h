#pragma once
#include "Scene.h"
#include <vector>
#include <chrono>

using namespace std :: chrono;

class Game
{

private:

	const double TIME_INCREMENT = 0.4;
	const long UPDATE_PERIOD = 10;

	milliseconds initialMilliseconds;
	long lastUpdatedTime;

	Scene* activeScene;	
	vector<Scene*> scenes;

//	Vector3D gravity = Vector3D(0, 0, 9.8);


public:

	Game() : activeScene(nullptr) , 
		     initialMilliseconds(duration_cast<milliseconds>(system_clock ::now().time_since_epoch())),
	         lastUpdatedTime(0){}

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);
};