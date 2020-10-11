#include "App.h"
#include <sstream>
#include <iomanip>

float sceenWidth = 800;
float screenHeight = 600;
App::App()
	:
	wnd(sceenWidth, screenHeight, "SturdyGoggles")
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
	wnd.Gfx().DrawTestTriangle(
		timer.Peek(),
		// dividing the variable by 2 so the range is 0 - 2
		// then minus 1 so the final value is between -1 and 1
		wnd.mouse.GetPosX() / (sceenWidth / 2) - 1.0f,
		// normalizing the Y pos so that when the mouse moves down the screen
		// it is read as expected by the user
		-wnd.mouse.GetPosY() / (screenHeight / 2) + 1.0f
	);
	///
	wnd.Gfx().EndFrame();
}