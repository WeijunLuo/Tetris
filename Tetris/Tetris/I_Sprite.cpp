#include "I_Sprite.h"



I_Sprite::I_Sprite()
{
	glm::vec3 color = glm::vec3(0,1,0);

	moveData[0] = 0;
	moveData[1] = 4;
	moveData[2] = 1;
	moveData[3] = 4;
	moveData[4] = 2;
	moveData[5] = 4;
	moveData[6] = 3;
	moveData[7] = 4;

	moveSprite[0] = new Sprite(getPosition(moveData[0], moveData[1]),glm::vec2(0.1f, 0.08f),color);
	moveSprite[1] = new Sprite(getPosition(moveData[2], moveData[3]),glm::vec2(0.1f, 0.08f), color);
	moveSprite[2] = new Sprite(getPosition(moveData[4], moveData[5]),glm::vec2(0.1f, 0.08f), color);
	moveSprite[3] = new Sprite(getPosition(moveData[6], moveData[7]),glm::vec2(0.1f, 0.08f), color);
}


I_Sprite::~I_Sprite()
{
}
bool I_Sprite::moveDown()
{

		int minX = 0;
		int minY = 0;

		//找到图形的最低点
		for (int i = 0; i < sizeof(moveData) / sizeof(moveData[0]); i += 2)
		{
			if (minX < moveData[i])
			{
				minX = moveData[i];
				minY = moveData[i + 1];
			}
		}
		//已经到最低
		if (minX == 19) return true;

		bool checkResult = false;
		for (int i = 0; i < sizeof(moveData) / sizeof(moveData[0]); i += 2)
		{
			if (GamePlay::Instance()->data[moveData[i] + 1][moveData[i + 1]] != nullptr)
			{
				checkResult = true;
				break;
			}
		}

		//未碰撞到其他对象
		if (!checkResult)
		{
			for (int i = 0; i < sizeof(moveData) / sizeof(moveData[0]); i += 2)
				moveData[i]++;
			int m = 0;
			for (int i = 0; i < sizeof(moveSprite) / sizeof(moveSprite[0]); i++)
			{
				moveSprite[i]->position = getPosition(moveData[m], moveData[m + 1]);
				m += 2;
			}

		}
		//碰撞到其他对象
		else			
			return true;

	return false;

}
void I_Sprite::turnRight()
{

}
void I_Sprite::moveLeft()
{
	int minX = 10;
	int minY = 20;
	for (int i = 0; i < sizeof(moveData) / sizeof(moveData[0]); i += 2)
	{
		if (minY > moveData[i + 1])
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
			if (GamePlay::Instance()->data[moveData[i]][moveData[i + 1] - 1] != nullptr)
			{
				checkResult = true;
				break;
			}
		}
		if (checkResult)return;
		else
		{

			//moveSprite->position += glm::vec2(-0.1f,0);
			for (int i = 0; i < sizeof(moveData) / sizeof(moveData[0]); i += 2)
				moveData[i + 1]--;
			int m = 0;
			for (int i = 0; i < sizeof(moveSprite) / sizeof(moveSprite[0]); i++)
			{
				moveSprite[i]->position = getPosition(moveData[m], moveData[m + 1]);
				m += 2;
			}
		}
	}
}
void I_Sprite::moveRight()
{
	int maxX = 0;
	int maxY = 0;
	for (int i = 0; i < sizeof(moveData) / sizeof(moveData[0]); i += 2)
	{
		if (maxY < moveData[i + 1])
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
			if (GamePlay::Instance()->data[moveData[i]][moveData[i + 1] + 1] != 0)
			{
				checkResult = true;
				break;
			}
		}

		if (checkResult)return;
		else
		{
			for (int i = 0; i < sizeof(moveData) / sizeof(moveData[0]); i += 2)
				moveData[i + 1]++;
			int m = 0;
			for (int i = 0; i < sizeof(moveSprite) / sizeof(moveSprite[0]); i++)
			{
				moveSprite[i]->position = getPosition(moveData[m], moveData[m + 1]);
				m += 2;
			}
		}
	}
}
void I_Sprite::saveData()
{
	int m = 0;
	for (int i = 0; i < sizeof(moveSprite) / sizeof(moveSprite[0]); i++)
	{
		GamePlay::Instance()->data[moveData[m]][moveData[m + 1]] = moveSprite[i];
		m += 2;
	}
}
void I_Sprite::rend()
{
	for (int i = 0; i < sizeof(moveSprite) / sizeof(moveSprite[0]); i++)
		moveSprite[i]->render(*ShaderManager::Instance()->GetShader("sprite"));
}