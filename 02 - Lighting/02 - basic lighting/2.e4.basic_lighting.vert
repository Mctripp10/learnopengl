#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 LightingColor; // resulting color from lighting calculations

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);

    // gouraud shading
    // -------------------------
    vec3 Position = vec3(model * vec4(aPos, 1.0));
    vec3 Normal = mat3(transpose(inverse(model))) * aNormal;

    // ambient
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    // diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - Position);
    float diffIntensity = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diffIntensity * lightColor;

    // specular
    float specularStrength = 1.0; // this is set higher to better show the effect of Gouraud shading 
    float shininess = 5.0;
    vec3 viewDir = normalize(viewPos - Position);
    vec3 reflectDir = reflect(-lightDir, norm);
    float specIntensity = pow(max(dot(viewDir, reflectDir), 0.0), pow(2, shininess));
    vec3 specular = specularStrength * specIntensity * lightColor;

    LightingColor = ambient + diffuse + specular;
} 

// PHONG VS. GOURAUD SHADING (note from book)
//
// In the earlier days of lighting shaders, developers used to implement the Phong 
// lighting model in the vertex shader. The advantage of doing lighting in the vertex 
// shader is that it is a lot more efficient since there are generally a lot less 
// vertices compared to fragments, so the (expensive) lighting calculations are done 
// less frequently. However, the resulting color value in the vertex shader is the 
// resulting lighting color of that vertex only and the color values of the surrounding 
// fragments are then the result of interpolated lighting colors. The result was that the
// lighting was not very realistic unless large amounts of vertices were used:
//
// --See image on website
//
// When the Phong lighting model is implemented in the vertex shader it is called Gouraud
// shading instead of Phong shading. Note that due to the interpolation the lighting looks 
// somewhat off. The Phong shading gives much smoother lighting results.