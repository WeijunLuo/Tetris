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
	if (GamePlay::Instance()->data[xx][yy] != nullptr)
		return true;
	else
	{
		//setPointData(x,xx,y,yy);
		*x = xx;
		*y = yy;
		return false;
	}
}

