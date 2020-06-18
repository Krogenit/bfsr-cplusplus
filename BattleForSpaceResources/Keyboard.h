#include <GLFW\glfw3.h>
#include <map>

using namespace std;

#pragma once
class Keyboard
{
public:
	struct Key;
	static map<int, bool*> keyMap;

	static bool* KEY_W;
	static bool* KEY_ESC;

	static bool isKeyPress(Key key);
	static void registerKeys();
	static void setKeyState(int key, bool isPress);
	static void onInput(GLFWwindow* window, int key, int scancode, int action, int mods);
private:
	Keyboard() {}
};