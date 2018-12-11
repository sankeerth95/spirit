//
// Created by sankeerth on 11/17/18.
//

#ifndef SPIRIT_FPSSTATE_H
#define SPIRIT_FPSSTATE_H


#include <glm/ext.hpp>
#include "GameState.h"
#include "Mesh.h"
#include "Texture.h"

class FPSState : public GameState {

private:
    void dfs_mesh(aiNode *node, glm::mat4 global_transform);

public:

    glm::vec3 position;
    glm::vec3 eye;
    glm::vec3 up;
    int mvp_location;
    glm::mat4 proj;
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 mvp;

    std::vector<Texture*> textures;

    FPSState();


    void set_shaders() override;

    void update() override;

    void draw() override;

    Mesh* getMesh(int i, glm::mat4 global_transform) override;

};

#endif //SPIRIT_FPSSTATE_H
