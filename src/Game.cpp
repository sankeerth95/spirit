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

Game::Game(GLFWwindow *window): d(2) {

    switch_state(new FPSState());

    Controller::setController(window);
}

void Game::update() {

    if(Controller::key_esc)
        switch_state(new MenuState());
    gs->update();
}

void Game::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for(int i = d.num_buffers; i >= 0; i--)
        d.draw(i);
}


void Game::dfs_mesh(aiNode *node, glm::mat4 global_transform) {

    glm::mat4 trns = global_transform*glm::make_mat4(&(node->mTransformation[0][0]));

    for(int i = 0; i < node->mNumMeshes; i++)
        d.update(gs->getMesh(node->mMeshes[i], trns), node->mMeshes[i]);

    for(int i = 0; i < node->mNumChildren; i++)
        dfs_mesh(node->mChildren[i], trns);


}

void Game::switch_state(GameState *new_state) {

    gs = new_state;
    gs->set_shaders();

    dfs_mesh(gs->sc->getScene()->mRootNode, glm::mat4(1.0f));

    d.loadMaterials(gs->sc->getScene());

}
