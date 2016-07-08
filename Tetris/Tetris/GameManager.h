#pragma once
#include <GL\glew.h>
#include "GamePlay.h"
enum GameState{UIMenu=0,Game,GameOver};
class GameManager
{
public:
	static bool KeyCode[1024];
	~GameManager();
	void init();
	void update(GLfloat deltime);
	void startGame();
	void PlayGame();
	void GameOver();
	static GameManager* Instance();

private:
	static GameManager* m_instance;
	GameState State;
	GameManager();
};

