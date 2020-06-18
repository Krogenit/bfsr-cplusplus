#include "FpsCounter.h"

int ticks, fps;
time_t prevTime;

FpsCounter::FpsCounter()
{
	prevTime = time(0);
}

void FpsCounter::update()
{
	ticks++;
	time_t now = time(0);
	if (now - prevTime >= 1)
	{
		fps = ticks;
		ticks = 0;
		prevTime = now;
		getFps();
	}
}

void FpsCounter::getFps()
{
	
}