#include "App.h"
#include "ChiliTimer.h"
#include "HelperFunctions.h"



App::App()
	:
	wnd(800, 600, "Good Shit")
{}

int App::Go()
{
	while (true)
	{
		// process all messages pending, but to not block for new messages
		if (const auto ecode = Window::ProcessMessages())
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		
		DoFrame();
	}
}





void App::DoFrame()
{
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(c, c, 1.0f);

	/*wnd.Gfx().DrawTestTriangle(-timer.Peek(),
		0.0f,
		0.0f);*/

	wnd.Gfx().DrawTestPyramid(timer.Peek() * 2, 1.5f, 0.7f);

	wnd.Gfx().DrawTestTriangle(timer.Peek()* 1.5,
		wnd.mouse.GetPosX() / 400.0f - 1.0f,
		-wnd.mouse.GetPosY() / 300.0f + 1.0f);
	wnd.Gfx().EndFrame();

	
}