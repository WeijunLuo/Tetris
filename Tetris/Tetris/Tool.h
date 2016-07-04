#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
class Tool
{
public:
	inline static  const char* ReadFile(const char* file)
	{
		string data;
		try
		{
			ifstream is(file);
			stringstream dd;
			dd << is.rdbuf();

			is.close();

			data = dd.str();
			return data.c_str();

		}
		catch (exception e)
		{
			cout << "can't read the file " << file << endl;
			cout<<e.what() << endl;
		}
		return NULL;
	}
};