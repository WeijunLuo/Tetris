#pragma once
#include <glm\glm.hpp>
#include <cmath>
#include "Sprite.h"
class IModeSpite
{
public:
	int m_length;
	int s_length;

	int *moveData;
	Sprite **moveSprite;

	IModeSpite();
	~IModeSpite();
	 virtual void turnRight() = 0;
	void rend();
	bool moveDown();
	void moveLeft();
	void moveRight();
	void saveData();
	glm::vec2 getPosition(int x, int y);
	glm::vec2 getRotatePoint(glm::vec2 point, glm::vec2 origin,float angle);
	bool checkPoint(int *x,int *y,glm::vec2 point, glm::vec2 origin, float angle);
};

