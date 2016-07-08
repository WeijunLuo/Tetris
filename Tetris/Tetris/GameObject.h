#pragma once
#include<glm\glm.hpp>
#include "Shader.h"
using namespace glm;
class GameObject
{
public:

	glm::vec2 position;
	glm::vec2 rotation;
	glm::vec2 scale;
	glm::vec2 velocity;

	virtual void render(Shader shader)=0;
	virtual void update(GLfloat delt) = 0;

	


	GameObject(glm::vec2 pos,glm::vec2 rot,glm::vec2 scale,glm::vec2 vel);
	~GameObject();
};

