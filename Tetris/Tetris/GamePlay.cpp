#include "GamePlay.h"
#include "Tool.h"
#include <list>
glm::vec2 getPosition(int x, int y);
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
			data[i][m] = nullptr;
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
	for (int i = 0; i < 20; i++)
	{
		for(int m=0;m<10;m++)
			if(data[i][m] != nullptr)
				data[i][m]->render(*ShaderManager::Instance()->GetShader("sprite"));
	}
	if (IsMoveNow)
	{
		IsMoveNow = false;
		int type = rand() % 2;	
		switch (type)
		{
		case 0:
			{
				moveSprite = new I_Sprite();
				break;
			}
		case 1:
		{
			moveSprite = new O_Spite();
			break;
		}
		case Mode::T:
		{

		}
		case Mode::Z:
		{

		}
		default:
			break;
		}

	}
	if (!IsMoveNow)
	{
		//moveSpriteControll();
		/*if (moveSprite == nullptr)
		{
			timeControll = 0;
			return;
		}*/
		//moveSprite->update(deltime);
		moveSpriteControll();
		if (moveSprite == nullptr)return;
		moveSprite->rend();
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
		moveSprite->moveLeft();

	}
	if (GameManager::KeyCode[GLFW_KEY_D])
	{
		GameManager::KeyCode[GLFW_KEY_D] = false;
		moveSprite->moveRight();
	}
	if (GameManager::KeyCode[GLFW_KEY_S])
	{
		checkMoveSprite();
	}
	

}
void GamePlay::checkMoveSprite()
{
	
	if (moveSprite != nullptr)
	{
		bool result = moveSprite->moveDown();
		if (result)
		{
			moveSprite->saveData();
			clear();
			moveSprite = nullptr;
			IsMoveNow = true;
		}

	}

	
}
glm::vec2 getPosition(int x, int y)
{
	float dis_y;
	if (x == 9)dis_y = 0;
	else if (x > 9)dis_y = -(x - 9);
	else dis_y = 9 - x;

	float yy = dis_y * 0.08f;

	float dis_x;
	if (y == 4)dis_x = 0;
	else if (y >= 4)dis_x = y - 4;
	else dis_x = -(4 - y);

	float xx = dis_x * 0.1f;
	return glm::vec2(xx, yy);

}
void GamePlay::clear()
{
	std::list<int> clearCount;
	for (int i = 0; i < 20; i++)
	{
		bool canClear = true;
		for (int m = 0; m < 10; m++)
		{
			if (data[i][m] == nullptr)
			{
				canClear = false;
				break;
			}
		}
		if (canClear)
		{
			clearCount.push_back(i);
			for (int m = 0; m < 10; m++)
			{
				delete data[i][m];
				data[i][m] = nullptr;
			}
		}


	}
	std::list<int>::iterator ite;
	for (ite = clearCount.begin(); ite != clearCount.end(); ++ite)
	{
		for (int i = 0;i < 10; i++)
		{
			for (int m = (*ite)-1; m >= 0; m--)
			{
				if (data[m][i] != nullptr)
				{
					data[m + 1][i] = data[m][i];
					data[m + 1][i]->position = getPosition(m+1,i);
					data[m][i] = nullptr;
				}
			}
		}
	}
	
}