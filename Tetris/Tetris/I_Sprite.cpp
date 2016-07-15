#include "I_Sprite.h"



I_Sprite::I_Sprite()
{

	moveData = new int[10];
	moveSprite = new Sprite*[5];

	m_length = 10;
	s_length = 5;

	moveData[0] = 0;
	moveData[1] = 4;
	moveData[2] = 1;
	moveData[3] = 4;
	moveData[4] = 2;
	moveData[5] = 4;
	moveData[6] = 3;
	moveData[7] = 4;
	moveData[8] = 4;
	moveData[9] = 4;
	glm::vec3 color = glm::vec3(rand() % 10 * 0.1f, rand() % 10 * 0.1f, rand() % 10 * 0.1f);
	moveSprite[0] = new Sprite(getPosition(moveData[0], moveData[1]),glm::vec2(0.1f, 0.08f),color);
	color = glm::vec3(rand() % 10 * 0.1f, rand() % 10 * 0.1f, rand() % 10 * 0.1f);
	moveSprite[1] = new Sprite(getPosition(moveData[2], moveData[3]),glm::vec2(0.1f, 0.08f), color);
	color = glm::vec3(rand() % 10 * 0.1f, rand() % 10 * 0.1f, rand() % 10 * 0.1f);
	moveSprite[2] = new Sprite(getPosition(moveData[4], moveData[5]),glm::vec2(0.1f, 0.08f), color);
	color = glm::vec3(rand() % 10 * 0.1f, rand() % 10 * 0.1f, rand() % 10 * 0.1f);
	moveSprite[3] = new Sprite(getPosition(moveData[6], moveData[7]),glm::vec2(0.1f, 0.08f), color);
	color = glm::vec3(rand() % 10 * 0.1f, rand() % 10 * 0.1f, rand() % 10 * 0.1f);
	moveSprite[4] = new Sprite(getPosition(moveData[8], moveData[9]), glm::vec2(0.1f, 0.08f), color);
}


I_Sprite::~I_Sprite()
{
	delete []moveData;
	delete[] moveSprite;
}

void I_Sprite::turnRight()
{
	glm::vec2 origin = glm::vec2(moveData[4],moveData[5]);

		if (checkPoint(&(moveData[0]), &(moveData[1]), glm::vec2(moveData[0], moveData[1]), origin, 270))
			return;
		if (checkPoint(&(moveData[2]), &(moveData[3]), glm::vec2(moveData[2], moveData[3]), origin, 270))
			return;
		if (checkPoint(&(moveData[6]), &(moveData[7]), glm::vec2(moveData[6], moveData[7]), origin, 270))
			return;
		if (checkPoint(&(moveData[8]), &(moveData[9]), glm::vec2(moveData[8], moveData[9]), origin, 270))
			return;	
		int m = 0;
		for (int i = 0; i < s_length; i++)
		{
			moveSprite[i]->position = getPosition(moveData[m], moveData[m + 1]);
			m += 2;
		}
}



