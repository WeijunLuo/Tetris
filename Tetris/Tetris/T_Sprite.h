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
};

