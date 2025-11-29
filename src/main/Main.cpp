#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"



GLfloat vertices[] = {
    -0.5f, -0.25f * float(sqrt(3)), 0.0f, // lower left corner
        0.5f, -0.25f * float(sqrt(3)), 0.0f, // lower right corner
        0.0f,  0.25f * float(sqrt(3)), 0.0f, // upper corner
    -0.5f / 2, 0.0f, 0.0f, // Inner left corner
        0.5f / 2, 0.0f, 0.0f, // Inner right corner
        0.0f,  -0.25f * float(sqrt(3)), 0.0f, // Inner lower corner
};

GLuint indices[] = {
    0, 3, 5, // Lower left triangle
    3, 2, 4, // Lower right triangle
    5, 4, 1  // Upper triangle
};
    

int main(int argc, char** argv) {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Rasterizer", NULL, NULL);
    if (window == NULL) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 800); 
    /* Create Vertex Shader Object and get reference,
       then attach vertex shader source to vertex shader obect
       compile the vertex shader into machine code*/
    
    Shader shaderProgram(
        "resource_files/Shaders/default.vert", 
        "resource_files/Shaders/default.frag");

    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));

    VAO1.LinkVBO(VBO1, 0);
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();
    
    
    while (!glfwWindowShouldClose(window)) {

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // Tell OPENGL to use the shader program
        shaderProgram.Activate();
        // Bind the VAO
        VAO1.Bind();
        // Draw the triangles

        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
        
        glfwSwapBuffers(window);


        glfwPollEvents();
    }

    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}