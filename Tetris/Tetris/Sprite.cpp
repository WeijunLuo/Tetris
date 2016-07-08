#include "Sprite.h"

SpriteRender* Sprite::sr;
Sprite::Sprite(glm::vec2 pos, glm::vec2 rot, glm::vec2 scale, glm::vec2 velocity)
	:GameObject(pos,rot,scale,velocity)
{
	if (sr == nullptr)
		sr = new SpriteRender();
}



Sprite::~Sprite()
{

}
void Sprite::render(Shader shader)
{
	glm::mat4 mode;
	mode = glm::translate(mode, glm::vec3(position.x, position.y, 0));
	mode = glm::scale(mode, glm::vec3(scale.x, scale.y, 1.0f));
	shader.SetShaderMat4("mode",mode);
	sr->render(shader);
}
void Sprite::update(GLfloat delt)
{
	position += velocity * delt;
}

