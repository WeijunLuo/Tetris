#pragma once
#include<glm\glm.hpp>
#include "Shader.h"
class GameObject
{
public:

	glm::vec2 position;
	glm::vec3 rotation;
	glm::vec3 scale;
	glm::vec3 velocity;

	virtual void render(Shader shader)=0;

	


	GameObject();
	~GameObject();
};

