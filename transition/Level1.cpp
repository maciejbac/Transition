#include "Level1.h"
#include "Circle.h"

void Level1::load()
{
	background = new SpriteSheet(L"Assets/general/background.png", gfx);
	worker = new SpriteSheet(L"Assets/worker/worker.png", gfx, 72, 72);
	land = new SpriteSheet(L"Assets/tiles/angled/isometric_pixel_flat_0016.png", gfx, 36, 50);
	tree = new SpriteSheet(L"Assets/general/tree.png", gfx, 128, 128);
	red = new SpriteSheet(L"Assets/general/red.png", gfx);
	crt = new SpriteSheet(L"Assets/general/crt.png", gfx);
	frame = 0;
	posX = 0;
	posX2 = 0;
	accumulator = 0;
	opacity = 0;
	flip = true;
}

void Level1::unload()
{
	delete land;
	delete background;
	delete worker;
}

void Level1::render()
{
	gfx->clearScreen(0.25f, 0.25f, 0.5f);
	background->draw(1.0f);

	for (int i = 0; i < 1600; i+=72)
	{
		land->draw(0, i, 180, 1.0);
	}

	land->draw(0, 1300, 500, 1.0);
	land->draw(0, 1228, 500, 1.0);
	land->draw(0, 1300, 552, 1.0);
	land->draw(0, 1228, 552, 1.0);

	worker->draw(frame + 2, posX, 100, 1.0);
	worker->draw(frame + 67, posX2, 100, 1.0);
	tree->draw(0, 1200, 300, 1.0);
	worker->draw(frame + 21, 1230, 470, 1.0);
	
	
	//red->draw(opacity);
	crt->draw(0.1);
	if(accumulator% 5 == 0) artifacts();

}

void Level1::update(double timeTotal, double timeDelta)
{
	accumulator++;
	if (accumulator == 4)
	{
		if (frame < 20)
		{
			frame += 5;
		}
		else
		{
			frame = 0;
		}
		accumulator = 0;
	}

	if (flip == true)
	{
		opacity += 0.01;
		if (opacity > 0.4)
		{
			flip = false;
		}
	}
	else
	{
		opacity -= 0.01;
		if (opacity < 0.01)
		{
			flip = true;
		}
	}

	posX += 200.0 * timeDelta;
	if (posX > 1600) posX = -100;

	posX2 -= 200.0 * timeDelta;
	if (posX2 < -200) posX2 = 1600;

}

void Level1::artifacts()
{
	float rand1 = rand() % (3 + 1 - 1) + 1;
	rand1 = rand1 / 10;
	gfx->drawCircle(rand() % (1600 + 1 - 100) + 100, rand() % (900 + 1 - 100) + 1, rand() % (60 + 1 - 1) + 1, 0.1, 1, 1, 1, rand1);
}