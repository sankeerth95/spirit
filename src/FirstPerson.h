//
// Created by sankeerth on 12/15/18.
//

#ifndef SPIRIT_FIRSTPERSON_H
#define SPIRIT_FIRSTPERSON_H

#include <glm/ext.hpp>
#include <vector>
#include "Texture.h"


class FirstPerson {


    glm::vec3 position;
    glm::vec3 eye;
    glm::vec3 up;
    int mvp_location;
    glm::mat4 proj;
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 mvp;

    std::vector<Texture*> textures;

    void update();
};


#endif //SPIRIT_FIRSTPERSON_H
