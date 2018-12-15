//
// Created by sankeerth on 11/15/18.
//

#ifndef SPIRIT_GAMESTATE_H
#define SPIRIT_GAMESTATE_H


#include "Shader.h"
#include "Mesh.h"
#include "SceneImporter.h"
#include "DrawableStatic.h"

class GameState {

public:
    int numMeshes;
    SceneImporter *sc;

    DrawableStatic *d;

    virtual void set_shaders()=0;

    virtual void update()=0;
    virtual void draw()=0;
//    virtual Mesh *getMesh(int i, glm::mat4 global_transform) =0;

};


#endif //SPIRIT_GAMESTATE_H
