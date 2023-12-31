#pragma once
class Color
{

private:

	float redComponent;
	float greenComponent;
	float blueComponent;


public:

	Color(float red = 0, float green = 0, float blue = 0) : redComponent(red), greenComponent(green), blueComponent(blue) {}

	inline float GetRedComponent() const { return this->redComponent; }
	inline float GetGreenComponent() const { return this->greenComponent; }
	inline float GetBlueComponent() const { return this->blueComponent; }

	inline void SetRed(const float& redComponentToSet) { if (redComponentToSet >= 0 && redComponentToSet <= 1) this->redComponent = redComponentToSet; }
	inline void SetGreen(const float& greenComponentToSet) { if (greenComponentToSet >= 0 && greenComponentToSet <= 0) this->greenComponent = greenComponentToSet; }
	inline void SetBlue(const float& blueComponentToSet) { if (blueComponentToSet >= 0 && blueComponentToSet <= 0) this->blueComponent = blueComponentToSet; }

};
