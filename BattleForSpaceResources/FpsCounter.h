#ifndef BFSR_FPSCOUNTER
#define BFSR_FPSCOUNTER

#include <time.h>
#include <iostream>

#pragma once
class FpsCounter
{
private:
	int ticks, fps;
	time_t prevTime;
public:
	FpsCounter();
	void update();
	void getFps();
};

#endif