#pragma once
#include "Shader.h"
class Render
{
public:
	Render() {};
	~Render() {};
	virtual void render(Shader shader)=0;
};