#include "Sprite.h"
#include "GamePlay.h"

SpriteRender* Sprite::sr;
Sprite::Sprite( glm::vec2 pos, glm::vec2 scale,glm::vec3 col, glm::vec2 rot, glm::vec2 velocity)
	:GameObject(pos, rot, scale, velocity), color(glm::vec4(rand() % 10 * 0.1f, rand() % 10 * 0.1f, rand() % 10 * 0.1f, 1))
	,timeControl(0)
{
	if (sr == nullptr)
		sr = new SpriteRender();
	color = col;
}



Sprite::~Sprite()
{

}
void Sprite::render(Shader shader)
{
	glm::mat4 mode;
	mode = glm::translate(mode, glm::vec3(position.x-scale.x/2, position.y+scale.y/2, 0));
	mode = glm::scale(mode, glm::vec3(scale.x, scale.y, 1.0f));
	shader.SetShaderMat4("mode",mode);
	shader.SetShaderVec3("_color", color);

	sr->render(shader);
}
void Sprite::update(GLfloat delt)
{
	/*if (timeControl == 0)
	{
		std::list<glm::vec2>::iterator ite;
		for (ite = posInfo->begin(); ite != posInfo->end(); ++ite)
		{
			GamePlay::Instance()->data[(int)(*ite).x][(int)(*ite).y] = 1;
		}
	}
	else if (timeControl > 1)
	{
		std::list<glm::vec2>::iterator ite;
		for (ite = posInfo->begin(); ite != posInfo->end(); ++ite)
		{
			GamePlay::Instance()->data[(int)(*ite).x][(int)(*ite).y] = 0;
			GamePlay::Instance()->data[(int)(*ite).x][(int)(*ite).y +1] = 0;
			(*ite) = glm::vec2((*ite).x,(*ite).y+1);
		}
	}
	else
		timeControl += delt;*/
	position += velocity * delt;
}

