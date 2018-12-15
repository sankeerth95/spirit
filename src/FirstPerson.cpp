//
// Created by sankeerth on 12/15/18.
//

#include <iostream>
#include "FirstPerson.h"
#include "Controller.h"


void FirstPerson::update() {

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

    d->shader->useProgram();

    glUniformMatrix4fv(mvp_location, 1, GL_FALSE, glm::value_ptr(mvp));

    d->shader->unUseProgram();

}

void FirstPerson::draw() {
    d->shader->useProgram();
    for(int i = d->num_buffers; i >= 0; i--)
        d->draw(i);
    d->shader->unUseProgram();

}


Mesh* FirstPerson::getMesh(int i, glm::mat4 global_transform) {
    const aiScene *sc1 = sc->getScene();
    if (!sc1) {
        std::cout << "Error" << std::endl;
        return nullptr;
    }

    Mesh *mm = new Mesh(sc1->mMeshes[i], global_transform);
//update drawable meshed
    return mm;
}

void FirstPerson::dfs_mesh(aiNode *node, glm::mat4 global_transform) {

    glm::mat4 trns = global_transform*glm::make_mat4(&(node->mTransformation[0][0]));

    for(int i = 0; i < node->mNumMeshes; i++)
        d->loadStaticMesh(getMesh(node->mMeshes[i], trns), node->mMeshes[i]);

    for(int i = 0; i < node->mNumChildren; i++)
        dfs_mesh(node->mChildren[i], trns);

}

FirstPerson::FirstPerson(): proj(1.0f), model(1.0f), view(1.0f) {

    d = new DrawableStatic(3);
    sc = new SceneImporter("res/cube_textured.fbx");
    numMeshes = sc->getScene()->mNumMeshes;


    dfs_mesh(sc->getScene()->mRootNode, glm::mat4(1.0f));
    d->loadMaterials(sc->getScene());


    d->shader = new Shader("res/vertex_shader1.vert", "res/fragment_shader1.frag");

}


void FirstPerson::init() {

    //TODO: should load all paths from a config file

    position = glm::vec3(0.0f, 0.0f, 1.5f);

    proj = glm::perspective(glm::radians(70.0f), 4.0f/3.0f, 0.3f, 15.0f);
    glm::mat4 mvp = proj*view*model;

    mvp_location = glGetUniformLocation(d->shader->getProgram(), "u_mvp");

//    int texloc1 = glGetUniformLocation(d->shader->getProgram(), "tex1_texture");

}

