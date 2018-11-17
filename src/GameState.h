//
// Created by sankeerth on 11/15/18.
//

#ifndef SPIRIT_GAMESTATE_H
#define SPIRIT_GAMESTATE_H


#include "Shader.h"

class GameState {

public:
    Shader *shader;
    virtual void set_shaders()=0;

    virtual void update()=0;

};


#endif //SPIRIT_GAMESTATE_H
