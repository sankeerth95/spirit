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

Game::Game(GLFWwindow *window): gs(new FPSState()), texture("res/tex1.jpg") {


    gs->set_shaders();

//    int light1_location = glGetUniformLocation(shader.getProgram(), "u_light1pos");
//    glm::vec3 ll;
//    glUniform3fv(light1_location, 1, &ll);

    SceneImporter sc("res/house_join.obj");
    const aiScene* sc1 = sc.getScene();
    if(!sc1){
        std::cout << "Error" <<std::endl;
        return;
    }

    texture.bind(0);

    Mesh *mm = new Mesh(sc1->mMeshes[0]);
    //update drawable meshed
    d.update(mm);


    Controller::setController(window);
}

void Game::update() {

    gs->update();

 }

void Game::render() {
    d.draw();
}
