//
// Created by sankeerth on 11/20/18.
//

#ifndef SPIRIT_MENUSTATE_H
#define SPIRIT_MENUSTATE_H


#include "GameState.h"

class MenuState : public GameState {
public:
    void set_shaders() override;

    void update() override;

    void draw() override;

    Mesh *getMesh(int i, glm::mat4 global_transform) override;

};

#endif //SPIRIT_MENUSTATE_H
