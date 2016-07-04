#include "ShaderManager.h"

ShaderManager* ShaderManager::m_instance = nullptr;

ShaderManager::ShaderManager()
{
}


ShaderManager::~ShaderManager()
{
}
ShaderManager* ShaderManager::Instance()
{
	if (m_instance == nullptr)
		m_instance = new ShaderManager();
	return m_instance;
}
bool check(char* file_name)
{
	return false;
}
void ShaderManager::loadShader(char* shader_index,char* file_name)
{
	Shaders[shader_index] =new Shader(file_name);
}
Shader* ShaderManager::GetShader(char* name)
{
	return Shaders[name];
}

