#pragma once
#include <Windows.h>
class HPTimer
{
	long long startTime;
	long long lastCallToUpdate;
	long long currentCallToUpdate;
	long long frequency;

public:
	HPTimer()
	{
		LARGE_INTEGER t;
		QueryPerformanceFrequency(&t);
		frequency = t.QuadPart;
		Reset();
	}
	
	void Reset()
	{
		LARGE_INTEGER t;
		QueryPerformanceCounter(&t);
		startTime = t.QuadPart;
		currentCallToUpdate = t.QuadPart;
		lastCallToUpdate = t.QuadPart;
	}

	void update()
	{
		lastCallToUpdate = currentCallToUpdate;
		LARGE_INTEGER t;
		QueryPerformanceCounter(&t);
		currentCallToUpdate = t.QuadPart;
	}

	double getTimeTotal()
	{
		double d = currentCallToUpdate - startTime;
		return d / frequency;
	}

	double getTimeDelta()
	{
		double d = currentCallToUpdate - lastCallToUpdate;
		return d / frequency;
	}

};

