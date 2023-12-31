#pragma once
#include "Scene.h"


class MenuScene : public Scene 
{

private:


	// meteor impact
public : 

	MenuScene() : Scene() {}
 
	void ProcessKeyPressed(unsigned char key, int px, int py);
};

