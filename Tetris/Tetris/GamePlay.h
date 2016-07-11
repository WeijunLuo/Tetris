#pragma once
#include "Sprite.h"
#include "ShaderManager.h"
#include "GameManager.h"
#include <GLFW\glfw3.h>
#include <list>
#include "GameView.h"
class GamePlay
{
public:

	int data[20][10];
	~GamePlay();
	void update(GLfloat deltime);
	static GamePlay* Instance();
private:
	GLfloat timeControll;
	int moveData[8];
	GameView gv;
	Bound GameBound;
	std::list<Sprite*> staticSprite;
	static GamePlay* m_instance;
	Sprite* moveSprite;
	GamePlay();
	void moveSpriteControll();
	void checkMoveSprite();
	void clear();
};

