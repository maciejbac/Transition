#pragma once
#include <Windows.h>
#include <d2d1.h>

class Graphics
{
	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* renderTarget;
	ID2D1SolidColorBrush* brush;

public:
	Graphics();
	~Graphics();

	bool init(HWND windowHandle);
	ID2D1RenderTarget* getRenderTarget() { return renderTarget; };
	void beginDraw() { renderTarget->BeginDraw(); }
	void endDraw() { renderTarget->EndDraw(); }
	void clearScreen(float r, float g, float b);
	void drawCircle(float x, float y, float radius, float radius2, float r, float g, float b, float a);
};