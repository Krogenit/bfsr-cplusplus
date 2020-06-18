#include "Mouse.h"

double Mouse::mouseX;
double Mouse::mouseY;
bool Mouse::leftDown, Mouse::rightDown, Mouse::isLeftRelease, Mouse::isRightRelease, Mouse::isNeedClear;

void Mouse::onMouseMove(GLFWwindow* window, double xpos, double ypos)
{
	mouseX = xpos;
	mouseY = ypos;
}

void Mouse::onMouseButton(GLFWwindow* window, int button, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		if (button == GLFW_MOUSE_BUTTON_LEFT)
			leftDown = true;
		if (button == GLFW_MOUSE_BUTTON_RIGHT)
			rightDown = true;
	}
	else
	{
		if (button == GLFW_MOUSE_BUTTON_LEFT)
		{
			isLeftRelease = true;
			leftDown = false;
		}

		if (button == GLFW_MOUSE_BUTTON_RIGHT)
		{
			isRightRelease = true;
			rightDown = false;
		}

	}
}

void Mouse::updateState(bool isBegin)
{
	if (isBegin)
	{
		if (isLeftRelease || isRightRelease)
			isNeedClear = true;
	}
	else
	{
		if (isNeedClear)
		{
			isNeedClear = false;
			isLeftRelease = false;
			isRightRelease = false;
		}
	}
}

bool Mouse::isLeftClicked()
{
	return isLeftRelease;
}

bool Mouse::isRightClicked()
{
	return isRightRelease;
}

void Mouse::registerMouse(GLFWwindow* window)
{
	glfwGetCursorPos(window, &mouseX, &mouseY);
}