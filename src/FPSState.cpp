//
// Created by sankeerth on 11/17/18.
//

#include <GL/glew.h>
#include <iostream>
#include "FPSState.h"
#include "Controller.h"
#include "SceneImporter.h"


FPSState::FPSState(): proj(1.0f), model(1.0f), view(1.0f) {
//    shader = new Shader("res/vertex_shader1.vert", "res/fragment_shader1.frag");
}

void FPSState::set_shaders() {
    //TODO: should load all paths from a config file
    shader = new Shader("res/vertex_shader1.vert", "res/fragment_shader1.frag");

    shader->useProgram();

    position = glm::vec3(0.0f, 0.0f, 0.2f);

    proj = glm::perspective(glm::radians(70.0f), 4.0f/3.0f, 0.1f, 3.0f);
    glm::mat4 mvp = proj*view*model;

    mvp_location = glGetUniformLocation(shader->getProgram(), "u_mvp");

}

Mesh* FPSState::getMesh() {
    SceneImporter sc("res/house_join.obj");
    const aiScene *sc1 = sc.getScene();
    if (!sc1) {
        std::cout << "Error" << std::endl;
        return nullptr;
    }

    Mesh *mm = new Mesh(sc1->mMeshes[0]);
//update drawable meshed
    return mm;

}


void FPSState::update() {

    float yaw_rad = glm::radians(Controller::mouse_yaw);
    float pitch_rad = glm::radians(Controller::mouse_pitch);


    glm::vec3 eye;
    eye.y = std::cos(yaw_rad) * std::cos(pitch_rad);
    eye.z = std::sin(pitch_rad);
    eye.x = std::sin(yaw_rad) * std::cos(pitch_rad);


    if (Controller::key_w){
        position.y += 0.00005f * std::cos(yaw_rad);
        position.x += 0.00005f * std::sin(yaw_rad);
    }
    glm::vec3 up = glm::vec3(0.0f, 0.0f, 1.0f);

   view = glm::lookAt(position, position+eye, up);
    mvp = proj*view*model;
    glUniformMatrix4fv(mvp_location, 1, GL_FALSE, glm::value_ptr(mvp));

}
