//
// Created by sankeerth on 11/17/18.
//

#include <GL/glew.h>
#include <iostream>
#include "FPSState.h"
#include "Controller.h"


FPSState::FPSState(): proj(1.0f), model(1.0f), view(1.0f) {
//    shader = new Shader("res/vertex_shader1.vert", "res/fragment_shader1.frag");

    d = new Drawable(2);

    sc = new SceneImporter("res/cube_textured.fbx");
    numMeshes = sc->getScene()->mNumMeshes;


    dfs_mesh(sc->getScene()->mRootNode, glm::mat4(1.0f));
    d->loadMaterials(sc->getScene());


    shader = new Shader("res/vertex_shader1.vert", "res/fragment_shader1.frag");

}

void FPSState::set_shaders() {
    //TODO: should load all paths from a config file

    shader->useProgram();

    position = glm::vec3(0.0f, 0.0f, 1.5f);

    proj = glm::perspective(glm::radians(70.0f), 4.0f/3.0f, 0.3f, 15.0f);
    glm::mat4 mvp = proj*view*model;

    mvp_location = glGetUniformLocation(shader->getProgram(), "u_mvp");

    int texloc1 = glGetUniformLocation(shader->getProgram(), "tex1_texture");
    glUniform1i(texloc1, 0);


}


Mesh* FPSState::getMesh(int i, glm::mat4 global_transform) {
    const aiScene *sc1 = sc->getScene();
    if (!sc1) {
        std::cout << "Error" << std::endl;
        return nullptr;
    }

    Mesh *mm = new Mesh(sc1->mMeshes[i], global_transform);
//update drawable meshed
    return mm;
}


void FPSState::update() {

    float yaw_rad = glm::radians(Controller::mouse_yaw);
    float pitch_rad = glm::radians(Controller::mouse_pitch);

    eye.y = std::cos(yaw_rad) * std::cos(pitch_rad);
    eye.z = std::sin(pitch_rad);
    eye.x = std::sin(yaw_rad) * std::cos(pitch_rad);

    if (Controller::key_w){
        position.y += 0.0005f * std::cos(yaw_rad);
        position.x += 0.0005f * std::sin(yaw_rad);
    }
    up = glm::vec3(0.0f, 0.0f, 1.0f);

    view = glm::lookAt(position, position+eye, up);
    mvp = proj*view*model;
    glUniformMatrix4fv(mvp_location, 1, GL_FALSE, glm::value_ptr(mvp));

}



void FPSState::draw() {

    for(int i = d->num_buffers; i >= 0; i--)
        d->draw(i);
}


void FPSState::dfs_mesh(aiNode *node, glm::mat4 global_transform) {

    glm::mat4 trns = global_transform*glm::make_mat4(&(node->mTransformation[0][0]));

    for(int i = 0; i < node->mNumMeshes; i++)
        d->loadStaticMesh(getMesh(node->mMeshes[i], trns), node->mMeshes[i]);

    for(int i = 0; i < node->mNumChildren; i++)
        dfs_mesh(node->mChildren[i], trns);

}

