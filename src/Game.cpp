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
#include "Drawable.h"
#include "MenuState.h"

Game::Game(GLFWwindow *window): /*gs(new FPSState()),*/ texture("res/tex1.jpg") {

    switch_state(new FPSState());
    texture.bind(0);

    Controller::setController(window);
}

void Game::update() {

    if(Controller::key_esc)
        switch_state(new MenuState());
    gs->update();

}

void Game::render() {
    d.draw();
}

void Game::switch_state(GameState *new_state) {

    gs = new_state;
    gs->set_shaders();


    d.update(gs->getMesh());

}
