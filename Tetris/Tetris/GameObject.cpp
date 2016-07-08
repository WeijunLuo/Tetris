#include "GameObject.h"


GameObject::GameObject(glm::vec2 pos, glm::vec2 rot, glm::vec2 size, glm::vec2 vel)
{
	this->position = pos;
	this->rotation = rot;
	this->scale = size;
	this->velocity = vel;
}


GameObject::~GameObject()
{
}
