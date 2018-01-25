#pragma once
#include "Graphics.h"
#include "SpriteSheet.h"

class GameLevel
{
protected:
	static Graphics * gfx;

public:
	static void init(Graphics* graphics)
	{
		gfx = graphics;
	}

	virtual void load() = 0;
	virtual void unload() = 0;
	virtual void render() = 0;
	virtual void update(double timeTotal, double timeDelta) = 0;
};

