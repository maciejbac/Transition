#include "Graphics.h"
#include "GameController.h"
#include "HPTimer.h"

#include "Level1.h"

#define _name_ "01110100 01110010 01100001 01101110 01110011 01101001 01110100 01101001 01101111 01101110"
#define KEY_UP		72
#define KEY_DOWN	80
#define KEY_LEFT	75
#define KEY_RIGHT	77


void loadLevels();

Graphics* graphics; 

LRESULT CALLBACK WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam) 
{
	if (uMsg == WM_DESTROY)
	{
		PostQuitMessage(0);
		return 0;
	}
	
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR cmd,	int nCmdShow) 
{
	WNDCLASSEX window;
	ZeroMemory(&window, sizeof(WNDCLASSEX));
	window.cbSize = sizeof(WNDCLASSEX);
	window.hbrBackground = (HBRUSH)COLOR_WINDOW;
	window.hInstance = hInstance;
	window.lpfnWndProc = WindowProc;
	window.lpszClassName = "MainWindow";
	window.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClassEx(&window);

	RECT rect = {0, 0, 1600, 900 };
	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);

	HWND windowHandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, "MainWindow", _name_, WS_OVERLAPPEDWINDOW, 80, 80, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, 0);
	if (!windowHandle) return -1;

	graphics = new Graphics();
	
	if (!graphics->init(windowHandle))
	{
		delete graphics;
		return -1;
	}

	GameController::init();

	GameLevel::init(graphics);

	ShowWindow(windowHandle, nCmdShow);

	loadLevels();

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	HPTimer timer;

	UINT32 frameStart;
	int frameTime;


	MSG msg;
	msg.message = WM_NULL;

	while (msg.message != WM_QUIT) 
	{
		if (PeekMessage(&msg, windowHandle, 0, 0, PM_REMOVE))
		{
			DispatchMessage(&msg);
		}
		else
		{
			frameStart = timer.getTimeTotal();
			
			//Update
			GameController::update();

			//Render
			graphics->beginDraw();
			GameController::render();
			graphics->endDraw();
			
			frameTime = timer.getTimeTotal() - frameStart;

			if (frameDelay > frameTime)
			{
				Sleep(frameDelay - frameTime);
			}

		}
	}

	
	delete graphics;
	return 0;
}

void loadLevels()
{
	GameController::loadInitialLevel(new Level1());
}
