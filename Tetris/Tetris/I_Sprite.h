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
private:
	

};

