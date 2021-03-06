#pragma once
#include "GameObject.h"
#include <glm\glm.hpp>
#include "SpriteRender.h"
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <list>
class Sprite : public GameObject
{

public:
	glm::vec3 color;
	Sprite(glm::vec2 pos, glm::vec2 scale = glm::vec2(1, 1),glm::vec3 col = glm::vec3(0,0,0),glm::vec2 rot = glm::vec2(0,0),glm::vec2 velocity=glm::vec2(0,0));
	~Sprite();
	virtual void render(Shader shader);
	virtual void update(GLfloat delt);

private:
	GLfloat timeControl = 0;
	static SpriteRender* sr;
};

