#include "GameManager.h"
#include "ShaderManager.h"

GameManager::GameManager()
{

}


GameManager::~GameManager()
{
}
void GameManager::init()
{
	ShaderManager::Instance()->loadShader("test","sprite.ver");
}
