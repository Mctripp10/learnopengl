//#include <iostream>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//int main()
//{
//    glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f); // original vector we want to translate
//    glm::mat4 trans = glm::mat4(1.0f); // define matrix as identity matrix with 1.0 down the diagonal
//    trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f)); // translates given matrix (trans) by translation vector (1, 1, 0)
//    vec = trans * vec;  // compute translation (note order, it matters)
//    std::cout << vec.x << vec.y << vec.z << std::endl;
//}