#pragma once
#include <GL\glew.h>
class GameView
{
public:
	GLuint VAO;
	GameView();
	~GameView();
	void Init();
	void Rend();
};

