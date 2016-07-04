#include "Shader.h"
#include "Tool.h"
#include <iostream>
Shader::Shader(std::string file_name)
{
	this->shader_name = file_name;
	load_shaderCode();
}


Shader::~Shader()
{
}

void Shader::load_shaderCode()
{
	string vert_file = ShaderDirect + this->shader_name + ".vert";
	string frag_file = ShaderDirect + this->shader_name + ".frag";
	const char* vert = Tool::ReadFile(vert_file.c_str());
	const char* frag = Tool::ReadFile(frag_file.c_str());

	GLuint vertext_shader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

	compile_shader(vert,&vertext_shader);
	compile_shader(frag,&fragment_shader);

	this->shader = glCreateProgram();
	glAttachShader(shader,vertext_shader);
	glAttachShader(shader,fragment_shader);
	glLinkProgram(shader);



}
void Shader::compile_shader(const char* code,GLuint* shader)
{
	glShaderSource(*shader, 1, &code, NULL);
	glCompileShader(*shader);

	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(*shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(*shader, 512, NULL, infoLog);
		std::cout << "ERROR::COMPILATION_FAILED\n" << infoLog << std::endl;
		std::cout << code << endl;
	}
}
void Shader::use()
{
	glUseProgram(this->shader);
}
