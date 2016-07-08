#include "GamePlay.h"
GamePlay* GamePlay::m_instance = nullptr;
GamePlay* GamePlay::Instance()
{
	if (m_instance == nullptr)
		m_instance = new GamePlay();
	return m_instance;
}

GamePlay::GamePlay():moveSprite(nullptr),staticSprite()
{
	
}


GamePlay::~GamePlay()
{

}
void GamePlay::update(GLfloat deltime)
{
	if (moveSprite == nullptr)
		moveSprite = new Sprite(glm::vec2(0, 1), glm::vec2(0, 0), glm::vec2(1, 1), glm::vec2(0, -1.0f));
	if (moveSprite != nullptr)
	{
		moveSpriteControll();
		moveSprite->update(deltime);
		moveSprite->render(*ShaderManager::Instance()->GetShader("sprite"));
		checkMoveSprite();
	}

	std::list<Sprite*>::iterator ite;
	for (ite = staticSprite.begin(); ite != staticSprite.end(); ++ite)
	{
		(*ite)->render(*ShaderManager::Instance()->GetShader("sprite"));
	}
}
void GamePlay::moveSpriteControll()
{
	if (moveSprite == nullptr) return;
	if (GameManager::KeyCode[GLFW_KEY_A])
	{
		GameManager::KeyCode[GLFW_KEY_A] = false;
		moveSprite->velocity = glm::vec2(-10,moveSprite->velocity.y);
	}
	else if (GameManager::KeyCode[GLFW_KEY_D])
	{
		GameManager::KeyCode[GLFW_KEY_D] = false;
		moveSprite->velocity = glm::vec2(10,moveSprite->velocity.y);
	}
	else
	{
		moveSprite->velocity = glm::vec2(0,moveSprite->velocity.y);
	}
	//if(GameManager)
	

}
void GamePlay::checkMoveSprite()
{
	if(moveSprite->position.y<-0.75f)
	{
		Sprite* temp = &(*moveSprite);
		staticSprite.push_back(temp);
		moveSprite = nullptr;
	}
}