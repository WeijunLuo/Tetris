#version 330 core
uniform vec3 _color = vec3(1,0,0);
out vec4 color;
void main()
{
color = vec4(_color,1);
};