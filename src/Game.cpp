//
// Created by sankeerth on 11/15/18.
//
#include <GL/glew.h>
#include <assimp/scene.h>
#include <iostream>
#include "Game.h"
#include "Shader.h"
#include "Controller.h"
#include "SceneImporter.h"
#include "Texture.h"
#include "DrawableStatic.h"
#include "MenuState.h"

Game::Game(GLFWwindow *window) {
 //   d = new Drawable(2);


    switch_state(
            new FPSState()
            );

    Controller::setController(window);
}

void Game::update() {

    if(Controller::key_esc)
        switch_state(new MenuState());
    gs->update();
}

void Game::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gs->draw();
}

void Game::switch_state(GameState *new_state) {

    gs = new_state;
    gs->set_shaders();

}
