#pragma once
#include <glm\glm.hpp>
#include <GL\glew.h>
#include "Render.h"
class SpriteRender:public Render
{
public:
	GLuint VAO;
	SpriteRender();
	~SpriteRender();
	void render(Shader shader);
private:
	void init();
};

