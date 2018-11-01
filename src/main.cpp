#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include "Texture.h"
#include "SceneImporter.h"
#include "Drawable.h"


std::string parseShader(const std::string& path){

    std::ifstream f(path);
    std::stringstream ss;
    ss << f.rdbuf();

    return ss.str();
}

unsigned int create_shader(unsigned int type, const std::string &src){

    const char* cc = &src.c_str()[0];

    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &cc, nullptr);
    glCompileShader(shader);

//    glGetShaderiv(shader, GL_COMPILE_STATUS, )

    return shader;
}


int main()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Ascention", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if(glewInit() != GLEW_OK)
        return -2;

    std::cout << glGetString(GL_VERSION) << std::endl;



    unsigned int vertex_shader, fragment_shader;
    const std::string vPath = "/home/sankeerth/CLionProjects/spirit/res/vertex_shader1.vert";
    const std::string fPath = "/home/sankeerth/CLionProjects/spirit/res/fragment_shader1.frag";

    vertex_shader = create_shader(GL_VERTEX_SHADER, parseShader(vPath));
    fragment_shader = create_shader(GL_FRAGMENT_SHADER, parseShader(fPath));

    unsigned int program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
    glUseProgram(program);



    SceneImporter sc("/home/sankeerth/CLionProjects/spirit/res/cube.obj");
    const aiScene* sc1 = sc.getScene();
    if(!sc1)
        std::cout << "Error" <<std::endl;

    Drawable d;
    Mesh *mm = new Mesh(sc1->mMeshes[0]);
    d.update(mm);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        d.draw();
        // OpenGL draw call
//        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
