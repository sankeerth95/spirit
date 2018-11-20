//
// Created by sankeerth on 11/15/18.
//

#ifndef SPIRIT_GAME_H
#define SPIRIT_GAME_H


#include <GLFW/glfw3.h>
#include <glm/ext.hpp>
#include "Drawable.h"
#include "Texture.h"
#include "GameState.h"
#include "FPSState.h"


class Game {

public:
    GameState *gs;

    Drawable d;
    Texture texture;

    void switch_state(GameState *new_state);

    explicit Game(GLFWwindow * window);

    void update();
    void render();
};


#endif //SPIRIT_GAME_H
