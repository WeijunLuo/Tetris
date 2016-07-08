#pragma once
#include <glm\glm.hpp>
#include "Shader.h"
class Material
{
public:
	glm::vec3 Color;


	Material();
	~Material();
private:
	Shader *m_shader;
};

