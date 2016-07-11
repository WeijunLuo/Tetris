#version 330 core
uniform vec4 _color = vec4(1,0,0,1);
out vec4 color;
void main()
{
color = _color;
};