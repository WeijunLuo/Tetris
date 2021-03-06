#include "F_Sprite.h"


F_Sprite::F_Sprite()
{
	moveData = new int[8];
	moveSprite = new Sprite*[4];

	m_length = 8;
	s_length = 4;

	moveData[0] = 0;
	moveData[1] = 4;
	moveData[2] = 1;
	moveData[3] = 4;
	moveData[4] = 1;
	moveData[5] = 3;
	moveData[6] = 1;
	moveData[7] = 5;

	glm::vec3 color = glm::vec3(rand()%10*0.1f, rand() % 10 * 0.1f, rand() % 10 * 0.1f);
	moveSprite[0] = new Sprite(getPosition(moveData[0], moveData[1]), glm::vec2(0.1f, 0.08f),color);
	color = glm::vec3(rand() % 10 * 0.1f, rand() % 10 * 0.1f, rand() % 10 * 0.1f);
	moveSprite[1] = new Sprite(getPosition(moveData[2], moveData[3]), glm::vec2(0.1f, 0.08f),color);
	color = glm::vec3(rand() % 10 * 0.1f, rand() % 10 * 0.1f, rand() % 10 * 0.1f);
	moveSprite[2] = new Sprite(getPosition(moveData[4], moveData[5]), glm::vec2(0.1f, 0.08f),color);
	color = glm::vec3(rand() % 10 * 0.1f, rand() % 10 * 0.1f, rand() % 10 * 0.1f);
	moveSprite[3] = new Sprite(getPosition(moveData[6], moveData[7]), glm::vec2(0.1f, 0.08f),color);
}


F_Sprite::~F_Sprite()
{
	delete[]moveData;
	delete[] moveSprite;
}

void F_Sprite::turnRight()
{
	glm::vec2 origin = glm::vec2(moveData[2], moveData[3]);

	if (checkPoint(&(moveData[0]), &(moveData[1]), glm::vec2(moveData[0], moveData[1]), origin, 270))
		return;
	if (checkPoint(&(moveData[4]), &(moveData[5]), glm::vec2(moveData[4], moveData[5]), origin, 270))
		return;
	if (checkPoint(&(moveData[6]), &(moveData[7]), glm::vec2(moveData[6], moveData[7]), origin, 270))
		return;
	int m = 0;
	for (int i = 0; i < s_length; i++)
	{
		moveSprite[i]->position = getPosition(moveData[m], moveData[m + 1]);
		m += 2;
	}
}