#pragma once
#include "Window.h"
#include "SGTimer.h"
class App
{
public:
	App();
	// master frame / message loop
	int Run();
private:
	void DoFrame();
private:
	Window wnd;
	SGTimer timer;
};
