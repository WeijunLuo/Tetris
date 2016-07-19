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
};

