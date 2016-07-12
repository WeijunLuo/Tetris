#pragma once
#include "Sprite.h"
#include "GamePlay.h"
class F_Sprite :public IModeSpite
{
public:
	F_Sprite();
	~F_Sprite();
	virtual void turnRight();
	virtual bool moveDown();
	virtual void moveLeft();
	virtual void moveRight();
	virtual void saveData();
	virtual void rend();
	int moveData[12];
	Sprite* moveSprite[6];
};

