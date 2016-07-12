#pragma once
#include <glm\glm.hpp>
class IModeSpite
{
public:
	IModeSpite();
	~IModeSpite();
	virtual void rend() = 0;
	virtual void turnRight() = 0;
	virtual bool moveDown() = 0;
	virtual void moveLeft() = 0;
	virtual void moveRight() = 0;
	virtual void saveData() = 0;
	glm::vec2 getPosition(int x, int y);
};

