#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 textcoord;
uniform mat4 mode;
void main()
{
gl_Position = mode *vec4(position.x, position.y, position.z, 1.0);
}