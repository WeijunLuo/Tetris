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
		glUniformMatrix4fv(glGetUniformLocation(shader, key),1,GL_FALSE,glm::value_ptr(data));
	}
	inline void SetShaderVec4(const char* key, glm::vec4 &data)
	{
		//glUniform4fv(glGetUniformLocation(shader, key),)
		glUniform4f(glGetUniformLocation(shader, key), data.x, data.y, data.z, data.w);
	}
private:
	std::string shader_name;
	void load_shaderCode();
	void compile_shader(std::string code,GLuint* shader);

};

