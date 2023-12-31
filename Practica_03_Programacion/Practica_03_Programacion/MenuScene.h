#pragma once
#include "Scene.h"


class MenuScene : public Scene 
{

private:



public : 

	MenuScene() : Scene() {}
 
	void ProcessKeyPressed(unsigned char key, int px, int py);
};

