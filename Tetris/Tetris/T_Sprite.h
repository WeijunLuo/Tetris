#pragma once
#include "IModeSpite.h"
#include "Sprite.h"
#include "GamePlay.h"
class T_Sprite :public IModeSpite
{
public:
	T_Sprite();
	~T_Sprite();
	virtual void turnRight();
	virtual bool moveDown();
	virtual void moveLeft();
	virtual void moveRight();
	virtual void saveData();
	virtual void rend();
	int moveData[8];
	Sprite* moveSprite[4];
};

