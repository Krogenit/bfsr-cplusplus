#include <GLFW\glfw3.h>

#pragma once
class Mouse
{
public:

	static double mouseX, mouseY;
	static bool leftDown, rightDown, isLeftRelease, isRightRelease, isNeedClear;

	static void onMouseMove(GLFWwindow* window, double xpos, double ypos);
	static void onMouseButton(GLFWwindow* window, int button, int action, int mods);
	static void registerMouse(GLFWwindow* window);

	static void updateState(bool isBegin);

	static bool isLeftClicked();
	static bool isRightClicked();

private:
	Mouse();
};

