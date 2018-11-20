//
// Created by sankeerth on 11/20/18.
//

#include "MenuState.h"

void MenuState::set_shaders() {
    //memory management????
    shader = new Shader("res/vertex_shader_menu.vert", "res/fragment_shader_menu.frag");

    shader->useProgram();
/*
    position = glm::vec3(0.0f, 0.0f, 0.2f);

    proj = glm::perspective(glm::radians(70.0f), 4.0f/3.0f, 0.1f, 3.0f);
    glm::mat4 mvp = proj*view*model;

    mvp_location = glGetUniformLocation(shader->getProgram(), "u_mvp");
*/
}

void MenuState::update() {

}

Mesh *MenuState::getMesh() {
    return nullptr;
}
