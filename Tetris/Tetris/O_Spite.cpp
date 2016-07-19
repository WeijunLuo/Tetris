#include "O_Spite.h"



O_Spite::O_Spite()
{

	glm::vec3 color = glm::vec3(rand() % 10 * 0.1f, rand() % 10 * 0.1f, rand() % 10 * 0.1f);

	moveData = new int[8];
	moveSprite = new Sprite*[4];

	m_length = 8;
	s_length = 4;

	moveData[0] = 0;
	moveData[1] = 4;
	moveData[2] = 0;
	moveData[3] = 5;
	moveData[4] = 1;
	moveData[5] = 4;
	moveData[6] = 1;
	moveData[7] = 5;

	moveSprite[0] = new Sprite(getPosition(moveData[0], moveData[1]), glm::vec2(0.1f, 0.08f),color);
	color = glm::vec3(rand() % 10 * 0.1f, rand() % 10 * 0.1f, rand() % 10 * 0.1f);
	moveSprite[1] = new Sprite(getPosition(moveData[2], moveData[3]), glm::vec2(0.1f, 0.08f),color);
	color = glm::vec3(rand() % 10 * 0.1f, rand() % 10 * 0.1f, rand() % 10 * 0.1f);
	moveSprite[2] = new Sprite(getPosition(moveData[4], moveData[5]), glm::vec2(0.1f, 0.08f),color);
	color = glm::vec3(rand() % 10 * 0.1f, rand() % 10 * 0.1f, rand() % 10 * 0.1f);
	moveSprite[3] = new Sprite(getPosition(moveData[6], moveData[7]), glm::vec2(0.1f, 0.08f),color);
}


O_Spite::~O_Spite()
{
	delete[]moveData;
	delete[] moveSprite;
}

void O_Spite::turnRight()
{

}