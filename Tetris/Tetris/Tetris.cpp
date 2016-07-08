// Tetris.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define GLEW_STATIC
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "GameManager.h"
#include "ShaderManager.h"
#include "SpriteRender.h"
#include <iostream>
#include "Sprite.h"
#include "Tetris.h"

const GLint SCREEN_WIDTH = 600;
const GLint SCREEN_HEIGHT = 600;
GLfloat deltaTime, lastFrame;
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			GameManager::KeyCode[key] = true;
		else if (action == GLFW_RELEASE)
			GameManager::KeyCode[key] = false;
	}
}
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
	glGetError(); 


	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glfwSetKeyCallback(window, keyCallback);
	GameManager::Instance()->init();
	

	//ShaderManager::Instance()->loadShader("sprite", "sprite");
	//SpriteRender* sr = new SpriteRender();
	//Sprite* sp = new Sprite(glm::vec2(0, 0), glm::vec2(0,0),glm::vec2(1,1),glm::vec2(0,-1));
	

	while (!glfwWindowShouldClose(window))
	{
		// Calculate delta time
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glfwPollEvents();
		
		//sp->update(deltaTime);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		GameManager::Instance()->update(deltaTime);

		//sp->render(*ShaderManager::Instance()->GetShader("sprite"));
		//ShaderManager::Instance()->GetShader("sprite")->use();
		//sr->render(*ShaderManager::Instance()->GetShader("sprite"));


		//glUseProgram(shaderProgram);
		//glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES,0,3);


		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return 0;
}

