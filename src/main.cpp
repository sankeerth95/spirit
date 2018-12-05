#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "Game.h"


int main() {

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow *window = glfwCreateWindow(640, 480, "Ascention", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if(glewInit() != GLEW_OK)
        return -2;

    Game g(window);
    /* Loop until the user closes the window */
    glEnable(GL_DEPTH_TEST);
    glfwSwapInterval(1);
    while (!glfwWindowShouldClose(window))
    {

        g.update();
        g.render();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
