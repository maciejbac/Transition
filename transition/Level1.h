#pragma once
#include "GameLevel.h"
#include "GameController.h"

class Level1: public GameLevel
{
	SpriteSheet* background;
	SpriteSheet* worker;
	SpriteSheet* land;
	SpriteSheet* red;
	SpriteSheet* tree;
	SpriteSheet* crt;
	int frame;
	int posX, posX2;
	int accumulator; 
	float opacity;
	bool flip;

	void artifacts();

public:
	void load()	  override;
	void unload() override;
	void render() override;
	void update(double timeTotal, double timeDelta) override;
};

