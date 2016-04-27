#version 330 core

layout(location = 0) in vec2 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec2 vertexUV;

out vec4 fragColor;
out vec2 fragPos;
out vec2 fragmentUV; // just pass to Fragment Shader

void main()
{
    gl_Position = vec4(position, 0.0, 1.0);
    fragColor = color;
    fragPos = position;
    fragmentUV = vertexUV;
}