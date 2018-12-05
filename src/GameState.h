//
// Created by sankeerth on 11/15/18.
//

#ifndef SPIRIT_GAMESTATE_H
#define SPIRIT_GAMESTATE_H


#include "Shader.h"
#include "Mesh.h"
#include "SceneImporter.h"

class GameState {

public:
    int numMeshes;
    Shader *shader;
    SceneImporter *sc;

    virtual void set_shaders()=0;

    virtual void update()=0;

    virtual Mesh* getMesh(int i)=0;

};


#endif //SPIRIT_GAMESTATE_H
