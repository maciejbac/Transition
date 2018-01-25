#include "Circle.h"

Circle::Circle()
{
	circleX = 0;
	circleY = 0;
	circleRadius = 0;
	circleR = 0;
	circleG = 0;
	circleB = 0;
	circleA = 0;
}

Circle::~Circle()
{
}

void Circle::setValues(float x, float y, float radius, float r, float g, float b, float a)
{
	circleX = x;
	circleY = y;
	circleRadius = radius;
	circleR = r;
	circleG = g;
	circleB = b;
	circleA = a;
}
