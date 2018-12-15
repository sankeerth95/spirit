//
// Created by sankeerth on 11/17/18.
//

#ifndef SPIRIT_FPSSTATE_H
#define SPIRIT_FPSSTATE_H


#include <glm/ext.hpp>
#include "GameState.h"
#include "Mesh.h"
#include "Texture.h"
#include "FirstPerson.h"
#include "HUD.h"

class FPSState : public GameState {

private:
//    void dfs_mesh(aiNode *node, glm::mat4 global_transform);

public:

    FirstPerson *fp;
    HUD *hud;

    FPSState();


    void set_shaders() override;

    void update() override;

    void draw() override;

//    Mesh* getMesh(int i, glm::mat4 global_transform) override;

};

#endif //SPIRIT_FPSSTATE_H
