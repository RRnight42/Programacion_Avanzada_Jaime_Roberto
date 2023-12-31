#pragma once
#include "Solid.h"

class Text : public Solid
{

private:

	string texto;


public:

	Text(string text = "NewText") : Solid(), texto(text) {}


	inline Text getText() { return this->texto; }
	inline void setText(const string& text) { this->texto = text; }

	void Render();


};

