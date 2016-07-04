// Tetris.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define GLEW_STATIC
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "GameManager.h"
#include "ShaderManager.h"
#include "SpriteRender.h"

const GLint SCREEN_WIDTH = 800;
const GLint SCREEN_HEIGHT = 600;
GLfloat deltaTime, lastFrame;
int _tmain(int argc, _TCHAR* argv[])
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();
	glGetError(); // Call it once to catch glewInit() bug, all other errors are now from our application.

	//glfwSetKeyCallback(window, key_callback);

	// OpenGL configuration
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	/*GameManager gm;
	gm.init();*/

	ShaderManager::Instance()->loadShader("sprite", "sprite");
	SpriteRender* sr = new SpriteRender();
	

	while (!glfwWindowShouldClose(window))
	{
		// Calculate delta time
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glfwPollEvents();
		
		// Render
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		sr->render(*ShaderManager::Instance()->GetShader("sprite"));

		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return 0;
}

