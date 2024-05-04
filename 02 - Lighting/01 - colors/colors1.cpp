//#define STB_IMAGE_IMPLEMENTATION
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <stb_image/stb_image.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//#include <learnopengl/shader_m.h>
//
//#include <iostream>
//
//// Colors 1
//// Setting up a light source using two VAOs and two shaders to separate light source and other scene objects.
//// White cube is light source and organge cube is another scene object
//// 
//// 5-4-2024
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void processInput(GLFWwindow* window);
//glm::mat4 lookAt(glm::vec3 position, glm::vec3 target, glm::vec3 up);
//
//// settings
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//// camera
//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
//glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//
//float yaw = -90.0f;     // initialize to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left. 
//float pitch = 0.0f;
//float fov = 45.0f;
//
//// mouse
//bool firstMouse = true;
//float lastX = static_cast<float>(SCR_WIDTH) / 2.0f;
//float lastY = static_cast<float>(SCR_HEIGHT) / 2.0f;
//
//// timing
//float deltaTime = 0.0f;	// time between current frame and last frame
//float lastFrame = 0.0f;
//
//// lighting
//glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
//
//int main()
//{
//    // glfw: initialize and configure
//    // ------------------------------
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//    // glfw window creation
//    // --------------------
//    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//    // glad: load all OpenGL function pointers
//    // ---------------------------------------
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    // configure global opengl state
//    // -----------------------------
//    glEnable(GL_DEPTH_TEST);
//
//    // tell GLFW to capture cursor
//    // ---------------------------
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//    glfwSetCursorPosCallback(window, mouse_callback);
//
//    glfwSetScrollCallback(window, scroll_callback);
//
//    // build and compile our shader program
//    // ------------------------------------
//    Shader lightingShader("colors.vert", "colors.frag");
//    Shader lightCubeShader("lightSource.vert", "lightSource.frag");
//
//    // set up vertex data (and buffer(s)) and configure vertex attributes
//    // ------------------------------------------------------------------
//    float vertices[] = {
//        // positions
//        -0.5f, -0.5f, -0.5f, 
//         0.5f, -0.5f, -0.5f,  
//         0.5f,  0.5f, -0.5f,  
//         0.5f,  0.5f, -0.5f,
//        -0.5f,  0.5f, -0.5f, 
//        -0.5f, -0.5f, -0.5f,
//
//        -0.5f, -0.5f,  0.5f,
//         0.5f, -0.5f,  0.5f,
//         0.5f,  0.5f,  0.5f,
//         0.5f,  0.5f,  0.5f,
//        -0.5f,  0.5f,  0.5f,
//        -0.5f, -0.5f,  0.5f,
//
//        -0.5f,  0.5f,  0.5f,
//        -0.5f,  0.5f, -0.5f,
//        -0.5f, -0.5f, -0.5f,
//        -0.5f, -0.5f, -0.5f,
//        -0.5f, -0.5f,  0.5f,
//        -0.5f,  0.5f,  0.5f,
//
//         0.5f,  0.5f,  0.5f,
//         0.5f,  0.5f, -0.5f,
//         0.5f, -0.5f, -0.5f,
//         0.5f, -0.5f, -0.5f,
//         0.5f, -0.5f,  0.5f,
//         0.5f,  0.5f,  0.5f,
//
//        -0.5f, -0.5f, -0.5f,
//         0.5f, -0.5f, -0.5f,
//         0.5f, -0.5f,  0.5f,
//         0.5f, -0.5f,  0.5f,
//        -0.5f, -0.5f,  0.5f,
//        -0.5f, -0.5f, -0.5f,
//
//        -0.5f,  0.5f, -0.5f,
//         0.5f,  0.5f, -0.5f,
//         0.5f,  0.5f,  0.5f,
//         0.5f,  0.5f,  0.5f,
//        -0.5f,  0.5f,  0.5f,
//        -0.5f,  0.5f, -0.5f
//    };
//
//    unsigned int VBO, cubeVAO;
//    glGenVertexArrays(1, &cubeVAO);
//    glGenBuffers(1, &VBO);
//
//    // we only need to bind to the VBO, the container's VBO's data already contains the data.
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    glBindVertexArray(cubeVAO);
//
//    // set position attribute pointer
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    // second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
//    unsigned int lightCubeVAO;
//    glGenVertexArrays(1, &lightCubeVAO);
//    glBindVertexArray(lightCubeVAO);
//
//    // we only need to bind to the VBO (to link it with glVertexAttribPointer), no need to fill it; the VBO's data already contains all we need (it's already bound, but we do it again for educational purposes)
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//
//    // set position attribute pointer (this time for lightCubeVAO now that it is bound)
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    // render loop
//    // -----------
//    while (!glfwWindowShouldClose(window))
//    {
//        // per-frame time logic
//        // --------------------
//        float currentFrame = static_cast<float>(glfwGetTime());
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        // input
//        // -----
//        processInput(window);
//
//        // render
//        // ------
//        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        // be sure to activate shader when setting uniforms/drawing objects
//        lightingShader.use();
//        lightingShader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
//        lightingShader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);
//
//        // view/projection transformations
//        glm::mat4 projection = glm::perspective(glm::radians(fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//        glm::mat4 view = lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
//        lightingShader.setMat4("projection", projection);
//        lightingShader.setMat4("view", view);
//
//        // world transformation
//        glm::mat4 model = glm::mat4(1.0f);
//        lightingShader.setMat4("model", model);
//
//        // render the cube
//        glBindVertexArray(cubeVAO);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//
//        lightCubeShader.use();
//        lightCubeShader.setMat4("projection", projection);
//        lightCubeShader.setMat4("view", view);
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, lightPos);
//        model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
//        lightCubeShader.setMat4("model", model);
//
//        glBindVertexArray(lightCubeVAO);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//
//        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//        // -------------------------------------------------------------------------------
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    // optional: de-allocate all resources once they've outlived their purpose:
//    // ------------------------------------------------------------------------
//    glDeleteVertexArrays(1, &cubeVAO);
//    glDeleteVertexArrays(1, &lightCubeVAO);
//    glDeleteBuffers(1, &VBO);
//
//    // glfw: terminate, clearing all previously allocated GLFW resources.
//    // ------------------------------------------------------------------
//    glfwTerminate();
//    return 0;
//}
//
//// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//
//    float cameraSpeed = static_cast<float>(2.5 * deltaTime);
//    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//        cameraPos += cameraSpeed * cameraFront;             // Use camera front forward vector to move in forward/backward direction
//    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//        cameraPos -= cameraSpeed * cameraFront;
//    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;       // Do a cross product to create a right vector for left/right direction
//    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
//        cameraPos -= cameraUp * cameraSpeed;            // No need to do cross product since we already have an up vector to use for up/down direction
//    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
//        cameraPos += cameraUp * cameraSpeed;
//}
//
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    // make sure the viewport matches the new window dimensions; note that width and 
//    // height will be significantly larger than specified on retina displays.
//    glViewport(0, 0, width, height);
//}
//
//// glfw: whenever the mouse moves, this callback is called
//// -------------------------------------------------------
//void mouse_callback(GLFWwindow* window, double xposIn, double yposIn) {
//
//    float xpos = static_cast<float>(xposIn);
//    float ypos = static_cast<float>(yposIn);
//
//    if (firstMouse)
//    {
//        lastX = xpos;
//        lastY = ypos;
//        firstMouse = false;
//    }
//
//    float xoffset = xpos - lastX;
//    float yoffset = lastY - ypos;       // reversed since y-coordinates range form bottom to top
//    lastX = xpos;
//    lastY = ypos;
//
//    const float sensitivity = 0.1f;     // change to your liking
//    xoffset *= sensitivity;
//    yoffset *= sensitivity;
//
//    yaw += xoffset;
//    pitch += yoffset;
//
//    // make sure that when pitch is out of bounds, screen doesn't get flipped
//    if (pitch > 89.0f)
//        pitch = 89.0f;
//    if (pitch < -89.0f)
//        pitch = -89.0f;
//
//    glm::vec3 front;
//    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
//    front.y = sin(glm::radians(pitch));
//    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
//    cameraFront = normalize(front);
//}
//
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//    fov -= static_cast<float>(yoffset);
//    if (fov < 1.0f)
//        fov = 1.0f;
//    if (fov > 45.0f)
//        fov = 45.0f;
//}
//
//// Custom implementation of the LookAt function (Joey de Vries)
//glm::mat4 calculate_lookAt_matrix(glm::vec3 position, glm::vec3 target, glm::vec3 worldUp)
//{
//    // 1. Position = known
//    // 2. Calculate cameraDirection
//    glm::vec3 zaxis = glm::normalize(position - target);
//    // 3. Get positive right axis vector
//    glm::vec3 xaxis = glm::normalize(glm::cross(glm::normalize(worldUp), zaxis));
//    // 4. Calculate camera up vector
//    glm::vec3 yaxis = glm::cross(zaxis, xaxis);
//
//    // Create translation and rotation matrix
//    // In glm we access elements as mat[col][row] due to column-major layout
//    glm::mat4 translation = glm::mat4(1.0f); // Identity matrix by default
//    translation[3][0] = -position.x; // Fourth column, first row
//    translation[3][1] = -position.y;
//    translation[3][2] = -position.z;
//    glm::mat4 rotation = glm::mat4(1.0f);
//    rotation[0][0] = xaxis.x; // First column, first row
//    rotation[1][0] = xaxis.y;
//    rotation[2][0] = xaxis.z;
//    rotation[0][1] = yaxis.x; // First column, second row
//    rotation[1][1] = yaxis.y;
//    rotation[2][1] = yaxis.z;
//    rotation[0][2] = zaxis.x; // First column, third row
//    rotation[1][2] = zaxis.y;
//    rotation[2][2] = zaxis.z;
//
//    // Return lookAt matrix as combination of translation and rotation matrix
//    return rotation * translation; // Remember to read from right to left (first translation then rotation)
//}
//
//
//// Custom implementation of the LookAt function (MCT)
//glm::mat4 lookAt(glm::vec3 position, glm::vec3 target, glm::vec3 up)
//{
//    glm::vec3 direction = glm::normalize(position - target);
//    glm::vec3 right = glm::normalize(glm::cross(up, direction));
//    glm::vec3 cameraUp = glm::normalize(glm::cross(direction, right));
//
//    glm::mat4 lookAtMatrix = glm::mat4(1.0f);
//
//    float rotArr[16] = { right.x, right.y, right.z, 0, cameraUp.x, cameraUp.y, cameraUp.z, 0, direction.x, direction.y, direction.z, 0, 0, 0, 0, 1 };
//    float transArr[16] = { 1, 0, 0, -position.x, 0, 1, 0, -position.y,  0, 0, 1, -position.z, 0, 0, 0, 1 };
//
//    glm::mat4 rotation = glm::transpose(glm::make_mat4(rotArr));
//    glm::mat4 translation = glm::transpose(glm::make_mat4(transArr));
//
//    lookAtMatrix = rotation * translation;
//    return lookAtMatrix;
//}