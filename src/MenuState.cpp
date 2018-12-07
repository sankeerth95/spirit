//
// Created by sankeerth on 11/20/18.
//

#include "MenuState.h"

void MenuState::set_shaders() {
    //memory management????
    shader = new Shader("res/vertex_shader_menu.vert", "res/fragment_shader_menu.frag");

    shader->useProgram();
}


void MenuState::update() {

}


Mesh * MenuState::getMesh(int i, glm::mat4 global_transform) {
    return nullptr;
}
