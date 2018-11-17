//
// Created by sankeerth on 11/3/18.
//

#include "Controller.h"

static double last_x = 0.0, last_y = 0.0;

float Controller::mouse_yaw = 0.0f, Controller::mouse_pitch = 0.0f;
float Controller::mouse_sensitivity = 0.06f;

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
