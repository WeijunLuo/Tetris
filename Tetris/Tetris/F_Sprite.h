#pragma once
#include "Sprite.h"
#include "GamePlay.h"
class F_Sprite :public IModeSpite
{
public:
	F_Sprite();
	~F_Sprite();
	virtual void turnRight();
};

