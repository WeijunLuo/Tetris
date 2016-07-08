#include "GameManager.h"
#include "ShaderManager.h"
bool GameManager::KeyCode[1024];
GameManager* GameManager::m_instance;
GameManager* GameManager::Instance()
{
	if (m_instance == nullptr)
		m_instance = new GameManager();
	return m_instance;
}
GameManager::GameManager()
{

}


GameManager::~GameManager()
{
	delete m_instance;
}
void GameManager::init()
{
	//init shader
	ShaderManager::Instance()->loadShader("sprite","sprite");
}

void GameManager::update(GLfloat deltime)
{
	GamePlay::Instance()->update(deltime);
}
void GameManager::startGame()
{

}
void GameManager::PlayGame()
{

}
void GameManager::GameOver()
{

}
