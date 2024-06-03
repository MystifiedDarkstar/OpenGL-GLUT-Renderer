#pragma once
class Simulation;

namespace GLUTCallbacks
{
	void Init(Simulation* gl);
	void Display();
	void Timer(int preferredRefresh);
	void Keyboard(unsigned char key, int x, int y);
	void MouseMovementCallback(int x, int y);
	void SelectionMenu(int value);
}