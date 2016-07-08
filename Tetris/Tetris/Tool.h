#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "GameObject.h"
using namespace std;
class Tool
{
public:
	inline static  string ReadFile(const char* file)
	{
		string data;
		try
		{
			ifstream is(file);
			stringstream dd;
			dd << is.rdbuf();

			is.close();

			data = dd.str();
			return data;

		}
		catch (exception e)
		{
			cout << "can't read the file " << file << endl;
			cout<<e.what() << endl;
		}
		return NULL;
	}
	inline static unsigned char* ReadTexture(const char* file)
	{

	}
	inline static bool CheckAABB(glm::vec2 point,Bound bound)
	{
		if (bound.min.x <point.x && bound.max.x>point.x && bound.min.y<point.y && bound.max.y>point.y)
			return true;
		else
			return false;
	}
	inline static bool CheckAABB(Bound b1, Bound b2)
	{
		glm::vec2 top = b1.min + glm::vec2(0,b1.max.y - b1.min.y);
		glm::vec2 right = b1.min + glm::vec2(b1.max.y - b1.min.x,0);


		if (CheckAABB(top, b2))return true;
		if (CheckAABB(right, b2))return true;
		if (CheckAABB(b1.min, b2))return true;
		if (CheckAABB(b1.max, b2))return true;

		return false;
	}
};