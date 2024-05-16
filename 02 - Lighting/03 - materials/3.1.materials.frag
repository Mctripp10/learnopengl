#version 330 core
out vec4 FragColor;
  
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

in vec3 FragPos;
in vec3 Normal;

// Phong Lighting Model fragment shader    
void main()
{
    // ambient
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    // diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);

    float diffIntensity = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diffIntensity * lightColor;

    // specular
    float specularStrength = 0.5;
    float shininess = 5.0;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float specIntensity = pow(max(dot(viewDir, reflectDir), 0.0), pow(2, shininess));
    vec3 specular = specularStrength * specIntensity * lightColor;

    vec3 result = (ambient + diffuse + specular) * objectColor;
    FragColor = vec4(result, 1.0);
}