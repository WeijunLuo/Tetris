#pragma once
#include <string>
#include <GL\glew.h>
class Shader
{
public:
	const std::string ShaderDirect = "../Resources/Shader/";
	GLuint shader;

	Shader(std::string file_name);
	~Shader();
	void use();

private:
	std::string shader_name;
	void load_shaderCode();
	void compile_shader(const char* code,GLuint* shader);

};

