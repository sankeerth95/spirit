//
// Created by sankeerth on 11/3/18.
//

#ifndef SPIRIT_CONTROLLER_H
#define SPIRIT_CONTROLLER_H

#include <GLFW/glfw3.h>


class Controller {

public:
    static float mouse_yaw, mouse_pitch;
    static float mouse_sensitivity;
    static bool key_w, key_esc;

    static void setController(GLFWwindow *window);

};


#endif //SPIRIT_CONTROLLER_H
