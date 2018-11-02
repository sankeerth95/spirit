#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include "Texture.h"
#include "SceneImporter.h"
#include "Drawable.h"
#include "Shader.h"


int main()
{
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

    std::cout << glGetString(GL_VERSION) << std::endl;

    const std::string vPath = "res/vertex_shader1.vert";
    const std::string fPath = "res/fragment_shader1.frag";

    Shader shader(vPath, fPath);
    shader.useProgram();

    SceneImporter sc("res/cube.obj");
    const aiScene* sc1 = sc.getScene();
    if(!sc1)
        std::cout << "Error" <<std::endl;

    Drawable d;
    Mesh *mm = new Mesh(sc1->mMeshes[0]);
    //update drawable meshed
    d.update(mm);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // OpenGL draw call
        d.draw();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
