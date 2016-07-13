#pragma once
#include "IModeSpite.h"
#include "Sprite.h"
#include "GamePlay.h"
class I_Sprite:public IModeSpite
{
public:
	I_Sprite();
	~I_Sprite();
	virtual void turnRight();
	virtual bool moveDown();
	virtual void moveLeft();
	virtual void moveRight();
	virtual void saveData();
	virtual void rend();
	int moveData[10];
	Sprite* moveSprite[5];
private:
	

};

