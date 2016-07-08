#include "GameView.h"
#include "ShaderManager.h"


GameView::GameView()
{
	Init();
}


GameView::~GameView()
{

}
void GameView::Init()
{
	GLfloat vertices[] = {
		-0.5f,0.8f,0,
		-0.5f,-0.8f,0,
		0.5f,-0.8f,0,
		0.5f,0.8f,0
	};

	GLuint VBO;
	glGenBuffers(1,&VBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER,0);
	glBindVertexArray(0);

}
void GameView::Rend()
{
	
	ShaderManager::Instance()->GetShader("view")->use();
	glBindVertexArray(VAO);
	glDrawArrays(GL_LINE_LOOP,0,4);
	//lBindVertexArray(0);
	/*GLfloat v1[] = {-0.5f,0.8f};
	GLfloat v2[] = { -0.5f,-0.8f };
	GLfloat v3[] = { 0.5f,-0.8f };
	GLfloat v4[] = { 0.5f,0.8f };
	glBegin(GL_LINE);
	glColor3b(1,1,1);
	glVertex2fv(v1);
	glVertex2fv(v2);
	glVertex2fv(v3);
	glVertex2fv(v4);
	glEnd();
	glFlush();*/
}
