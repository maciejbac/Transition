#pragma once
#include <wincodec.h>
#include "Graphics.h"

class SpriteSheet
{
	Graphics* gfx;
	ID2D1Bitmap* bmp;
	int spriteWidth, spriteHeight;
	int spritesAccross;
	IWICBitmapFlipRotator* flipRotator;

public:
	SpriteSheet(wchar_t const* filename, Graphics* gfx);
	SpriteSheet(wchar_t const* filename, Graphics* gfx, int spriteWidth, int spriteHeight);
	~SpriteSheet();
	void draw(float opacity);
	void draw(int index, float x, float y, float opacity);
	void flip();
};

