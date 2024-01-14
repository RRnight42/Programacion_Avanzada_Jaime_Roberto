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

	int eliminatedAsteroids;
	int lives;

//	Vector3D gravity = Vector3D(0, 0, 9.8);


public:

	Game(int eliminatedAsteroids = 0 , int lives = 3) : activeScene(nullptr) , 
		                                                eliminatedAsteroids(eliminatedAsteroids), 
		                                                lives(lives),
		                                                initialMilliseconds(duration_cast<milliseconds>(system_clock ::now().time_since_epoch())),
	                                                    lastUpdatedTime(0){}

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);
	bool IsOver();
	bool Death();
	bool ShipLeaving();

	void DestroyAsteroids();
	void LoseLive();
	void ResetAsteroids();
};