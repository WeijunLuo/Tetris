#include "SpriteRender.h"


SpriteRender::SpriteRender()
{
	init();
}


SpriteRender::~SpriteRender()
{
}
void SpriteRender::init()
{
	/*GLuint VBO;

	GLfloat vertices[] = 
	{
		-0.5f,-0.5f,0,0,
		0.5f,0.5f,1,1,
		-0.5f,0.5f,0,1,

		-0.5f,-0.5f,0,0,
		0.5f,-0.5f,1,0,
		0.5f,0.5f,1,1

	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1,&VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);*/

	GLfloat vertices[] = {
		-0.5f,-0.5f,0,	0,0,
		0.5f,-0.5f,0,	0,1,
		0.5f,0.5f,0,	1,1,
		0.5f,0.5f,0,	1,1,
		-0.5f,0.5f,0,	1,0,
		-0.5f,-0.5f,0,  0,0	
	};
	GLuint VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);


}
void SpriteRender::render(Shader shader)
{
	shader.use();
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	//glDrawElements(GL_TRIANGLES,6,GL_FLOAT,)

}
