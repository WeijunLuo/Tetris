#pragma once
#include<glm\glm.hpp>
#include "Shader.h"
using namespace glm;
struct Bound
{
	glm::vec2 min;
	glm::vec2 max;
};
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

	inline Bound GetBoune()
	{
		Bound bound;
		//bound.min = glm::vec2(position - scale.y);
		bound.max = position + glm::vec2(scale.x/2,scale.y/2);
		bound.min = position - glm::vec2(scale.x / 2, scale.y / 2);
		return bound;
	}
};

