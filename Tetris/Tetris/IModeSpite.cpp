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

