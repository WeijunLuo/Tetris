#pragma once
#include <map>
#include <string>
#include "Shader.h"
#include <io.h>
class ShaderManager
{
public:
	static ShaderManager* Instance();
	std::map<std::string, Shader*> Shaders;
	void loadShader(char* shader_index, char* file_name);
	Shader* GetShader(char* name);
	~ShaderManager();
private:
	static ShaderManager* m_instance;
	ShaderManager();
};

