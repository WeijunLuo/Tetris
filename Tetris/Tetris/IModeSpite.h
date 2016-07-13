#pragma once
#include <glm\glm.hpp>
#include <cmath>
class IModeSpite
{
public:
	int rotation = 0;
	IModeSpite();
	~IModeSpite();
	virtual void rend() = 0;
	virtual void turnRight() = 0;
	virtual bool moveDown() = 0;
	virtual void moveLeft() = 0;
	virtual void moveRight() = 0;
	virtual void saveData() = 0;
	glm::vec2 getPosition(int x, int y);
	glm::vec2 getRotatePoint(glm::vec2 point, glm::vec2 origin,float angle);
	bool checkPoint(int *x,int *y,glm::vec2 point, glm::vec2 origin, float angle);
};

