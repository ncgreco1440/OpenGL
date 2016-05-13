#version 330 core

uniform vec4 colour;
uniform vec2 light_pos;

in DATA
{
    vec4 position;
    vec4 color;
} fs_in;

out vec4 color;

void main()
{
    float intensity = 1.0 / length(fs_in.position.xy - light_pos);
	//color = colour * intensity;
    color = fs_in.color * intensity;
}
