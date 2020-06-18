#include "Keyboard.h"

struct Keyboard::Key
{
public:
	bool isPress;

};
map<int, bool*> Keyboard::keyMap;

bool* Keyboard::KEY_W = new bool();
bool* Keyboard::KEY_ESC = new bool();

void Keyboard::registerKeys()
{
	keyMap[GLFW_KEY_W] = KEY_W;
	keyMap[GLFW_KEY_ESCAPE] = KEY_ESC;
}

bool Keyboard::isKeyPress(Keyboard::Key key)
{
	return key.isPress;
}

void Keyboard::setKeyState(int key, bool isPress)
{
	map<int, bool*>::iterator it = keyMap.find(key);
	if (it != keyMap.end())
	{
		*keyMap[key] = isPress;
	}
}

void Keyboard::onInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		setKeyState(key, true);
	}
	else if (action == GLFW_RELEASE)
	{
		setKeyState(key, false);
	}
}
