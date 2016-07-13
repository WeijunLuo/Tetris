#pragma once
#include "IModeSpite.h"
#include "Sprite.h"
#include "GamePlay.h"
class Z_Sprite :public IModeSpite
{
public:
	Z_Sprite();
	~Z_Sprite();
	virtual void turnRight();
	virtual bool moveDown();
	virtual void moveLeft();
	virtual void moveRight();
	virtual void saveData();
	virtual void rend();
	int moveData[10];
	Sprite* moveSprite[5];
};

