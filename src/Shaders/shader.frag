#version 330 core

in vec2 fragPos;
in vec4 fragColor;

out vec4 color;

uniform float time;

void main()
{
    //color = fragColor;
    //color = vec4(1.0, 0.0, 1.0, 1.0);
    /*color = fragColor + vec4(1.0 * (cos(time) + 1.0) * 0.5,
                            1.0 * (cos(time + 2.0) + 1.0) * 0.5,
                            1.0 * (sin(time) + 1.0) * 0.5, 0.0);*/
    color = vec4(fragColor.r * (cos(fragPos.x * 4.0 + time) + 1.0) * 0.5,
                 fragColor.g * (cos(fragPos.y * 8.0 + time) + 1.0) * 0.5,
                 fragColor.b * (cos(fragPos.x * 2.0 + time) + 1.0) * 0.5,
                 1.0);
}