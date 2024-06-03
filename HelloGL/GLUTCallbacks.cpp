#include "GLUTCallbacks.h"
#include "Simulation.h"

namespace GLUTCallbacks
{
	namespace
	{
		//initialise to a null pointer before we do anything
		Simulation* helloGL = nullptr;
	}
	void Init(Simulation* gl)
	{
		helloGL = gl;
	}
	void Display()
	{
		if (helloGL != nullptr)
		{
			helloGL->Display();
		}
	}
	void Timer(int preferredRate)
	{
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		helloGL->Update();
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
		glutTimerFunc(preferredRate - updateTime, GLUTCallbacks::Timer , preferredRate);
	}
	void Keyboard(unsigned char key, int x , int y)
	{
		helloGL->Keyboard(key,x ,y);
	}

	void MouseMovementCallback(int x, int y)
	{
		helloGL->MouseMovement(x, y);
	}

	void SelectionMenu(int value)
	{
		helloGL->SelectionMenuHandler(value);
	}
}