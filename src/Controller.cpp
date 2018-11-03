//
// Created by sankeerth on 11/3/18.
//

#include "Controller.h"

static float last_x = 320.0f, last_y = 240.0f;

float Controller::mouse_yaw, Controller::mouse_pitch;
float Controller::mouse_sensitivity = 0.05;

void mouse_callback(GLFWwindow *window, double xpos, double ypos){

    Controller::mouse_yaw += Controller::mouse_sensitivity*(xpos - last_x);
    Controller::mouse_pitch += Controller::mouse_sensitivity*(last_y - ypos);

    if( Controller::mouse_pitch > 89.0f)
        Controller::mouse_pitch = 89.0f;

    if( Controller::mouse_pitch < -89.0f)
        Controller::mouse_pitch = -89.0f;

    last_x = xpos;
    last_y = ypos;
}

void Controller::setController(GLFWwindow *window) {

    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

//    glfwSetKeyCallback(window, );
}
