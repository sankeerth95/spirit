//
// Created by sankeerth on 12/15/18.
//

#include "FirstPerson.h"
#include "Controller.h"

void FirstPerson::update() {

    float yaw_rad = glm::radians(Controller::mouse_yaw);
    float pitch_rad = glm::radians(Controller::mouse_pitch);

    eye.y = std::cos(yaw_rad) * std::cos(pitch_rad);
    eye.z = std::sin(pitch_rad);
    eye.x = std::sin(yaw_rad) * std::cos(pitch_rad);

    if (Controller::key_w){
        position.y += 0.0005f * std::cos(yaw_rad);
        position.x += 0.0005f * std::sin(yaw_rad);
    }
    up = glm::vec3(0.0f, 0.0f, 1.0f);

    view = glm::lookAt(position, position+eye, up);
    mvp = proj*view*model;


}

