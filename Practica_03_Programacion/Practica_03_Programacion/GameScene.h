#pragma once
#include "Scene.h"
class GameScene : public Scene
{



public:

	GameScene() : Scene() {}



	void ProcessKeyPressed(unsigned char key, int px, int py);


};

