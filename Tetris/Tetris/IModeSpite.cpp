#include "IModeSpite.h"



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

