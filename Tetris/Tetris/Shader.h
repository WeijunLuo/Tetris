#pragma once
#include <string>
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>
class Shader
{
public:
	const std::string ShaderDirect = "../Resources/Shader/";
	GLuint shader;

	Shader(std::string file_name);
	~Shader();
	void use();
	inline void SetShaderMat4(const char* key, glm::mat4 &data)
	{
		glUseProgram(shader);
		glUniformMatrix4fv(glGetUniformLocation(shader, key),1,GL_FALSE,glm::value_ptr(data));
	}
	inline void SetShaderVec3(const char* key, glm::vec3 &data)
	{
		glUseProgram(shader);
		//glUniform4fv(glGetUniformLocation(shader, key),)
		glUniform3f(glGetUniformLocation(shader, key), data.x, data.y, data.z);
	}
private:
	std::string shader_name;
	void load_shaderCode();
	void compile_shader(std::string code,GLuint* shader);

};

