#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include "Texture.h"
#include "SceneImporter.h"


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


    unsigned int vertex_array, vertex_buffer;
    glGenVertexArrays(1, &vertex_array);
    glBindVertexArray(vertex_array);

    float data[] = {0.0f, 0.0f, 0.0f, 0.0f,
                    0.0f, 1.0f, 0.0f, 1.0f,
                    1.0f, 0.0f, 1.0f, 0.0f,
                    1.0f, 1.0f, 1.0f, 1.0f};


    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, 16*sizeof(float), data, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4*sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4*sizeof(float), (void *) (2*sizeof(float) ) );
    glEnableVertexAttribArray(1);

    unsigned int indices[] = {
            0, 1, 2,
            1, 2, 3
    };

    unsigned int index_buffer;
    glGenBuffers(1, &index_buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6*sizeof(unsigned int), indices, GL_STATIC_DRAW);



    const std::string tex_path = "/home/sankeerth/CLionProjects/spirit/res/tex2.jpg";
    Texture tex1(tex_path);
    tex1.bind(2);

    int tex1_location = glGetUniformLocation(program, "tex1_texture");
    glUniform1i(tex1_location, 2);





    SceneImporter sc("/home/sankeerth/CLionProjects/spirit/res/cube.obj");
    sc.getScene();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // OpenGL draw call
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
