#pragma once
#include "Window.h"
#include "SGTimer.h"
#include "ImguiManager.h"
class App
{
public:
	App();
	// master frame / message loop
	int Run();
	~App();
private:
	void SimulatePhysics(float deltaTime);
	void HandleInput(float deltaTime);
	void RenderFrame(float deltaTime);
private:
	ImguiManager imgui;
	Window wnd;
	SGTimer timer;
	std::vector<std::unique_ptr<class Drawable>> drawables;
	float speed_factor = 1.0f;
	static constexpr size_t nDrawables = 180;
};
