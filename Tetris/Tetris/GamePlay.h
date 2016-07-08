#pragma once
#include "Sprite.h"
#include "ShaderManager.h"
#include "GameManager.h"
#include <GLFW\glfw3.h>
#include <list>
class GamePlay
{
public:

	~GamePlay();
	void update(GLfloat deltime);
	static GamePlay* Instance();
private:
	Bound GameBound;
	std::list<Sprite*> staticSprite;
	static GamePlay* m_instance;
	Sprite* moveSprite;
	GamePlay();
	void moveSpriteControll();
	void checkMoveSprite();
};

