#pragma once
#include "Sprite.h"
#include "GamePlay.h"
class O_Spite :public IModeSpite
{
public:
	O_Spite();
	~O_Spite();
	virtual void turnRight();
	virtual bool moveDown();
	virtual void moveLeft();
	virtual void moveRight();
	virtual void saveData();
	virtual void rend();
	int moveData[8];
	Sprite* moveSprite[4];
};

