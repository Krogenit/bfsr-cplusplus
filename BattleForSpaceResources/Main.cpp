#include <GLFW\glfw3.h>
#include <tinythread.h>

#include "Core.h"
#include "FpsCounter.h"

Core* core;

void checkGlError() {
	GLenum err(glGetError());

	while (err != GL_NO_ERROR) {
		std::string error;

		switch (err) {
		case GL_INVALID_OPERATION:      error = "INVALID_OPERATION";      break;
		case GL_INVALID_ENUM:           error = "INVALID_ENUM";           break;
		case GL_INVALID_VALUE:          error = "INVALID_VALUE";          break;
		case GL_OUT_OF_MEMORY:          error = "OUT_OF_MEMORY";          break;
		//case GL_INVALID_FRAMEBUFFER_OPERATION:  error = "INVALID_FRAMEBUFFER_OPERATION";  break;
		}

		std::cerr << "GL_" << error.c_str() << std::endl;
		err = glGetError();
	}
}

void onWindowResize(GLFWwindow* window, int width, int height)
{
	if (core != NULL)
	{
		core->resize(width, height);
	}

	glViewport(0, 0, width, height);
	glLoadIdentity();
	glOrtho(0, width, height, 0, 0.0F, 100.0F);
}

void setupOpenGL(GLFWwindow* window, int width, int height)
{
	//glShadeModel(GL_SMOOTH);
	//glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1F);
	glCullFace(GL_BACK);

	onWindowResize(window, width, height);
	TextureObject::loadPrimitives();

	glClearColor(0.25F, 0.5F, 1.0F, 1.0F);
}

GLFWwindow* init(int width, int height)
{
	GLFWwindow *window;

	if (!glfwInit())
	{
		return NULL;
	}

	window = glfwCreateWindow(width, height, "Battle For Space Resources", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return NULL;
	}

	glfwMakeContextCurrent(window);

	glfwSetWindowSizeCallback(window, onWindowResize);
	glfwSetKeyCallback(window, Keyboard::onInput);
	glfwSetCursorPosCallback(window, Mouse::onMouseMove);
	glfwSetMouseButtonCallback(window, Mouse::onMouseButton);

	setupOpenGL(window, width, height);

	return window;
}

void startUpdate(void * arg)
{
	core->updateThread();
}

void render()
{
	checkGlError();

	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	core->render();
}

void main()
{
	int screenWidth = 1280;
	int screenHeight = 720;

	GLFWwindow* window = init(screenWidth, screenHeight);
	core = new Core(window, screenWidth, screenHeight);
	
	tthread::thread t(startUpdate, 0);

	glfwSwapInterval(1);

	FpsCounter fpsCounter;

	while (!glfwWindowShouldClose(window))
	{
		render();
		fpsCounter.update();
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}