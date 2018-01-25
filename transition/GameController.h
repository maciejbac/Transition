#pragma once
#include "GameLevel.h"
#include "HPTimer.h"

class GameController
{
private:
	GameController() {};
	static GameLevel* currentLevel;
	static HPTimer* timer;
public:
	static void loadInitialLevel(GameLevel* level);
	static void switchLevel(GameLevel* level);
	static bool loading;
	static void init();
	static void render();
	static void update();
};

