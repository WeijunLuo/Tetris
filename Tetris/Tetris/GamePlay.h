#pragma once
#include "Sprite.h"
#include "ShaderManager.h"
#include "GameManager.h"
#include <GLFW\glfw3.h>
#include <list>
#include "GameView.h"
#include "IModeSpite.h"
#include "I_Sprite.h"
#include "O_Spite.h"
#include "T_Sprite.h"
class GamePlay
{
public:
	enum Mode
	{
		I = 0,
		O,
		T,
		Z
	};
	const int Width = 20;
	const int Height = 10;
	Sprite* data[20][10];
	~GamePlay();
	void update(GLfloat deltime);
	static GamePlay* Instance();
private:
	bool IsMoveNow = true;
	GLfloat timeControll;
	int moveData[8];
	Sprite* moveMode[4];
	GameView gv;
	Bound GameBound;
	std::list<Sprite*> staticSprite;
	static GamePlay* m_instance;
	IModeSpite* moveSprite;
	GamePlay();
	void moveSpriteControll();
	void checkMoveSprite();
	void clear();
};

