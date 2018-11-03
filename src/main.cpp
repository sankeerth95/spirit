#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <glm/ext.hpp>
#include <chrono>
#include <math.h>
#include "Texture.h"
#include "SceneImporter.h"
#include "Drawable.h"
#include "Shader.h"
#include "Controller.h"


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

    std::cout << glGetString(GL_VERSION) << std::endl;


    //TODO: should load all paths from a config file
    Shader shader("res/vertex_shader1.vert", "res/fragment_shader1.frag");
    shader.useProgram();


    glm::mat4 model(1.0f);
    glm::mat4 view(1.0f);
    glm::mat4 proj = //glm::ortho(-100.0f, 100.0f, -100.0f, 100.0f, -200.0f, 200.0f);
            glm::perspective(glm::radians(35.0f), 4.0f/3.0f, 0.1f, 100.0f);
    glm::mat4 mvp = proj*view*model;



    int mvp_location = glGetUniformLocation(shader.getProgram(), "u_mvp");
    glUniformMatrix4fv(mvp_location, 1, GL_FALSE, glm::value_ptr(mvp));


    SceneImporter sc("res/road.blend");
    const aiScene* sc1 = sc.getScene();
    if(!sc1){
        std::cout << "Error" <<std::endl;
        return -1;
    }

    Drawable d;
    Mesh *mm = new Mesh(sc1->mMeshes[0]);
    //update drawable meshed
    d.update(mm);


    Controller::setController(window);


    /* Loop until the user closes the window */
    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        std::cout << Controller::mouse_yaw <<" "<< Controller::mouse_pitch << std::endl;
//        if(Controller::mouse_yaw > 0.0)

        glm::vec3 eye;
        float yaw_rad = -glm::radians(Controller::mouse_yaw);
        float pitch_rad = -glm::radians(Controller::mouse_pitch);
        eye.z =  std::cos(yaw_rad)*std::cos(pitch_rad);
        eye.y = std::sin(pitch_rad);
        eye.x = std::sin(yaw_rad)*std::cos(pitch_rad);

        glm::vec3 right = glm::vec3(
                sin(yaw_rad - 3.14f/2.0f),
                0,
                cos(yaw_rad - 3.14f/2.0f)
        );

        glm::vec3 up = glm::cross(right, eye);

        float yy = std::sin(0.000006*(clock()));
        float xx = 3*yy;
        view = glm::lookAt(eye,
                           glm::vec3(0.0, 0.0, -3.0f), up);
        mvp = proj*view*model;
        glUniformMatrix4fv(mvp_location, 1, GL_FALSE, glm::value_ptr(mvp));

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
