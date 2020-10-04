#include "App.h"
#include <sstream>
#include <iomanip>

App::App()
	:
	wnd(800, 600, "SturdyGoggles")
{}

int App::Run()
{
	while (true)
	{
		// process all messages pending, but to not block for new messages
		if (const auto ecode = Window::ProcessMessages())
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		RenderFrame(0.1f);
	}
}

void App::SimulatePhysics(float deltaTime)
{
}

void App::HandleInput(float deltaTime)
{
}

void App::RenderFrame(float deltaTime)
{
	///example code to change the color of the background to black
	wnd.Gfx().ClearBuffer(0.0f, 0.0f, 0.0f);
	wnd.Gfx().DrawTestTriangle();
	///
	wnd.Gfx().EndFrame();
}