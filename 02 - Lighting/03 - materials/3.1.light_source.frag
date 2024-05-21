#version 330 core
out vec4 FragColor;

uniform vec3 ambient;
uniform vec3 diffuse;
uniform vec3 specular;
uniform vec3 lightColor;

void main()
{
    FragColor = vec4(lightColor, 0.0f);  // set all 4 vector values to 1.0
}