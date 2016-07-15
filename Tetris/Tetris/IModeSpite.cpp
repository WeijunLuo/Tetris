#include "IModeSpite.h"
#include "GamePlay.h"


IModeSpite::IModeSpite()
{
}


IModeSpite::~IModeSpite()
{
}
glm::vec2 IModeSpite::getPosition(int x, int y)
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
glm::vec2 IModeSpite::getRotatePoint(glm::vec2 point, glm::vec2 origin, float angle)
{
	glm::vec2 m_point = glm::vec2(point.y,-point.x);
	glm::vec2 m_origin = glm::vec2(origin.y,-origin.x);
	float d_angle = angle * 3.1415f / 180;

	float x = (m_point.x - m_origin.x) * std::cos(d_angle) - (m_point.y - m_origin.y)*std::sin(d_angle) + m_origin.x;
	float y = (m_point.x - m_origin.x) * std::sin(d_angle) + (m_point.y - m_origin.y)*std::cos(d_angle) + m_origin.y;

	return glm::vec2(-y,x);

}
bool IModeSpite::checkPoint(int *x, int *y, glm::vec2 point, glm::vec2 origin, float angle)
{
	glm::vec2 temp = getRotatePoint(point, origin, angle);
	int xx = std::nearbyint(temp.x);
	int yy = std::nearbyint(temp.y);
	if (GamePlay::Instance()->data[xx][yy] != nullptr || xx >= 20 || yy <= 0 || yy >= 10)
		return true;
	else
	{
		//setPointData(x,xx,y,yy);
		*x = xx;
		*y = yy;
		return false;
	}
}
void IModeSpite::rend()
{
	for (int i = 0; i < s_length; i++)
		moveSprite[i]->render(*ShaderManager::Instance()->GetShader("sprite"));
}
void IModeSpite::saveData()
{
	int m = 0;
	for (int i = 0; i < s_length; i++)
	{
		GamePlay::Instance()->data[moveData[m]][moveData[m + 1]] = moveSprite[i];
		m += 2;
	}
}
void IModeSpite::moveRight()
{
	int maxX = 0;
	int maxY = 0;
	for (int i = 0; i < m_length; i += 2)
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
		for (int i = 0; i < m_length; i += 2)
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
			for (int i = 0; i < m_length; i += 2)
				moveData[i + 1]++;
			int m = 0;
			for (int i = 0; i < s_length; i++)
			{
				moveSprite[i]->position = getPosition(moveData[m], moveData[m + 1]);
				m += 2;
			}
		}
	}
}
bool IModeSpite::moveDown()
{

	int minX = 0;
	int minY = 0;

	//找到图形的最低点
	for (int i = 0; i < m_length; i += 2)
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
	for (int i = 0; i < m_length; i += 2)
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
		for (int i = 0; i < m_length; i += 2)
			moveData[i]++;
		int m = 0;
		for (int i = 0; i < s_length; i++)
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
void IModeSpite::moveLeft()
{
	int minX = 10;
	int minY = 20;
	for (int i = 0; i < m_length; i += 2)
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
		for (int i = 0; i < m_length; i += 2)
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
			for (int i = 0; i < m_length; i += 2)
				moveData[i + 1]--;
			int m = 0;
			for (int i = 0; i < s_length; i++)
			{
				moveSprite[i]->position = getPosition(moveData[m], moveData[m + 1]);
				m += 2;
			}
		}
	}
}

