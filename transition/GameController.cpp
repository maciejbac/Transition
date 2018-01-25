#include "GameController.h"


GameLevel* GameController::currentLevel;
bool GameController::loading;
HPTimer* GameController::timer;
void GameController::init()
{
	loading = true;
	currentLevel = 0;
	timer = new HPTimer();
	double frametime = 1000000.0 / 60, delta = 0;
}

void GameController::loadInitialLevel(GameLevel* level)
{
	loading = true;
	currentLevel = level;
	currentLevel->load();
	loading = false;
}

void GameController::switchLevel(GameLevel* level)
{
	loading = true;
	currentLevel->unload();
	level->load();
	delete currentLevel;
	currentLevel = level;
	loading = false;
}

void GameController::render()
{
	if (loading) return;
	currentLevel->render();
}

void GameController::update()
{
	if (loading) return;
	timer->update();
	currentLevel->update(timer->getTimeTotal(), timer->getTimeDelta());
}
