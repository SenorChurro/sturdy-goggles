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
	void SimulatePhysics(float deltaTime);
	void HandleInput(float deltaTime);
	void RenderFrame(float deltaTime);
private:
	Window wnd;
	SGTimer timer;
};
