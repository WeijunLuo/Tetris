#include "GamePlay.h"
#include "Tool.h"
#include <list>
GamePlay* GamePlay::m_instance = nullptr;
//int GamePlay::data[30][50];
GamePlay* GamePlay::Instance()
{
	if (m_instance == nullptr)
		m_instance = new GamePlay();
	return m_instance;
}

GamePlay::GamePlay():moveSprite(nullptr),staticSprite(),GameBound(),gv()
{
	GameBound.min = glm::vec2(-0.5f,-1.0f);
	GameBound.max = glm::vec2(0.5f,1.0f);
	for (int i = 0; i < 20; i++)
		for (int m = 0; m < 10; m++)
			data[i][m] = 0;
	timeControll = 0;
	/*Sprite* temp4 = new Sprite(glm::vec2(0, -0.0f), glm::vec2(0, 0), glm::vec2(0.0f, 0.0f), glm::vec2(0, -0.4f));
	staticSprite.push_back(temp4);*/
}


GamePlay::~GamePlay()
{
	delete data;
}
void GamePlay::update(GLfloat deltime)
{

	gv.Rend();
	std::list<Sprite*>::iterator ite;
	for (ite = staticSprite.begin(); ite != staticSprite.end(); ++ite)
	{
		(*ite)->render(*ShaderManager::Instance()->GetShader("sprite"));
	}
	if (moveSprite == nullptr)
	{
		moveData[0] = 0;
		moveData[1] = 4;
		moveData[2] = 0;
		moveData[3] = 5;
		moveData[4] = 1;
		moveData[5] = 4;
		moveData[6] = 1;
		moveData[7] = 5;
		moveSprite = new Sprite(glm::vec2(0,0.8f), glm::vec2(0, 0), glm::vec2(0.2f, 0.16f), glm::vec2(0, -0.09f));
	}
	if (moveSprite != nullptr)
	{
		moveSpriteControll();
		if (moveSprite == nullptr)
		{
			timeControll = 0;
			return;
		}
		//moveSprite->update(deltime);
		moveSprite->render(*ShaderManager::Instance()->GetShader("sprite"));
		if (timeControll == 0)
		{			
			checkMoveSprite();
		}
		else if (timeControll > 1)
		{
			timeControll -= 1;
			checkMoveSprite();
		}
		timeControll += deltime;

		
	}

}
void GamePlay::moveSpriteControll()
{
	if (moveSprite == nullptr) return;
	if (GameManager::KeyCode[GLFW_KEY_A])
	{
		GameManager::KeyCode[GLFW_KEY_A] = false;
		int minX = 10;
		int minY = 20;
		for (int i = 0; i < sizeof(moveData) / sizeof(moveData[0]); i += 2)
		{
			if (minY > moveData[i+1])
			{
				minX = moveData[i];
				minY = moveData[i + 1];
			}
		}
		if (minY == 0)return;
		else
		{
			bool checkResult = false;
			for (int i = 0; i < sizeof(moveData) / sizeof(moveData[0]); i += 2)
				//data[moveData[i]][kmoveData[i + 1]] = 1;
			{
				if (data[moveData[i]][moveData[i +1]-1] != 0)
				{
					checkResult = true;
					break;
				}
			}
			if (checkResult)return;
			else
			{
				
				moveSprite->position += glm::vec2(-0.1f,0);
				for (int i = 0; i < sizeof(moveData) / sizeof(moveData[0]); i += 2)
					moveData[i+1]--;
			}
		}

	}
	if (GameManager::KeyCode[GLFW_KEY_D])
	{
		GameManager::KeyCode[GLFW_KEY_D] = false;
		
		int maxX = 0;
		int maxY = 0;
		for (int i = 0; i < sizeof(moveData) / sizeof(moveData[0]); i += 2)
		{
			if (maxY < moveData[i+1])
			{
				maxX = moveData[i];
				maxY = moveData[i + 1];
			}
		}
		if (maxY == 9)return;
		else
		{

			bool checkResult = false;
			for (int i = 0; i < sizeof(moveData) / sizeof(moveData[0]); i += 2)
			{
				if (data[moveData[i]][moveData[i + 1] + 1] != 0)
				{
					checkResult = true;
					break;
				}
			}

			if (checkResult)return;
			else
			{

				moveSprite->position += glm::vec2(0.1f, 0);
				for (int i = 0; i < sizeof(moveData) / sizeof(moveData[0]); i += 2)
					moveData[i+1]++;
			}
		}

	}
	if (GameManager::KeyCode[GLFW_KEY_S])
	{
		checkMoveSprite();
	}

	//if(GameManager)
	

}
//void GamePlay::checkMoveSprite()
//{
//	if(!Tool::CheckAABB(moveSprite->GetBoune().min, GameBound))
//	{
//		Sprite* temp = &(*moveSprite);
//		staticSprite.push_back(temp);
//		moveSprite = nullptr;
//		return;
//	}
//	else
//	{
//		std::list<Sprite*>::iterator ite;
//		for (ite = staticSprite.begin(); ite != staticSprite.end(); ++ite)
//		{
//			if (Tool::CheckAABB(moveSprite->GetBoune().min, (*ite)->GetBoune()))
//			{
//				Sprite* temp = &(*moveSprite);
//				staticSprite.push_back(temp);
//				moveSprite = nullptr;
//				return;
//			}
//			
//		}
//	}
//}
void GamePlay::checkMoveSprite()
{

	int minX = 0;
	int minY = 0;

	//找到图形的最低点
	for (int i = 0; i < sizeof(moveData)/sizeof(moveData[0]); i += 2)
	{
		if (minX < moveData[i])
		{
			minX = moveData[i];
			minY = moveData[i + 1];
		}
	}
	//已经到最低
	if(minX == 19)
	{
		moveSprite->position += glm::vec2(0, -0.08f);
		Sprite* temp = &(*moveSprite);
		staticSprite.push_back(temp);
		moveSprite = nullptr;

		for (int i = 0; i < sizeof(moveData) / sizeof(moveData[0]); i += 2)
			data[moveData[i]][moveData[i+1]] = 1;
		for (int i = 0; i < sizeof(moveData) / sizeof(moveData[0]); i ++)
			moveData[i] = 0;
		return;
	}

	bool checkResult = false;
	for (int i = 0; i < sizeof(moveData) / sizeof(moveData[0]); i += 2)
		//data[moveData[i]][kmoveData[i + 1]] = 1;
	{
		if (data[moveData[i] + 1][moveData[i + 1]] != 0)
		{
			checkResult = true;
			break;
		}
	}

	//未碰撞到其他对象
	if (!checkResult)
	{
		moveSprite->position += glm::vec2(0, -0.08f);
		for (int i = 0; i < sizeof(moveData) / sizeof(moveData[0]); i += 2)
			moveData[i]++;

	}
	//碰撞到其他对象
	else
	{
		moveSprite->position += glm::vec2(0, -0.08f);
		Sprite* temp = &(*moveSprite);
		staticSprite.push_back(temp);
		moveSprite = nullptr;
		for (int i = 0; i < sizeof(moveData) / sizeof(moveData[0]); i += 2)
			data[moveData[i]][moveData[i+1]] = 1;
		for (int i = 0; i < sizeof(moveData) / sizeof(moveData[0]); i ++)
			moveData[i] = 0;
	}

	
}
void GamePlay::clear()
{
	for (int i = 0; i < 20; i++)
	{
		bool canClear = true;
		for (int m = 0; m < 10; m++)
		{
			if (data[i][m] == 0)
			{
				canClear = false;
				break;
			}
		}
		if (canClear)
		{
			for (int m = 0; m < 10; m++)
				data[i][m] = 0;
		}

	}
}