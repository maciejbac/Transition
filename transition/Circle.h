#pragma once

class Circle
{
public:
	Circle();
	~Circle();
	void setValues(float x, float y, float radius, float r, float g, float b, float a);

	float circleX = 0;
	float circleY = 0;
	float circleRadius = 0;
	float circleR = 0;
	float circleG = 0;
	float circleB = 0;
	float circleA = 0;
};
