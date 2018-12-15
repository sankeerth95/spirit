//
// Created by sankeerth on 12/15/18.
//

#ifndef SPIRIT_FIRSTPERSON_H
#define SPIRIT_FIRSTPERSON_H

#include <glm/ext.hpp>
#include <vector>
#include "Texture.h"
#include "DrawableStatic.h"
#include "SceneImporter.h"


class FirstPerson {

public:

    DrawableStatic* d;
    int numMeshes;
    SceneImporter *sc;


    glm::vec3 position;
    glm::vec3 eye;
    glm::vec3 up;
    int mvp_location;
    glm::mat4 proj;
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 mvp;

    std::vector<Texture*> textures;

    FirstPerson();

    void init();
    Mesh* getMesh(int i, glm::mat4 global_transform);
    void dfs_mesh(aiNode *node, glm::mat4 global_transform);

    void update();
    void draw();

};


#endif //SPIRIT_FIRSTPERSON_H
