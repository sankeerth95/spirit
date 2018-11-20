//
// Created by sankeerth on 11/17/18.
//

#ifndef SPIRIT_FPSSTATE_H
#define SPIRIT_FPSSTATE_H


#include <glm/ext.hpp>
#include "GameState.h"
#include "Mesh.h"

class FPSState : public GameState {

public:


    glm::vec3 position;
    int mvp_location;
    glm::mat4 proj;
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 mvp;


    FPSState();

    void set_shaders() override;

    void update() override;

    Mesh* getMesh() override;

};

#endif //SPIRIT_FPSSTATE_H
