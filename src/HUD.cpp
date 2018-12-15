//
// Created by sankeerth on 12/15/18.
//

#include <iostream>
#include "HUD.h"

HUD::HUD() {

    d = new DrawableStatic(1);
    numMeshes = 1;


    std::vector<Vertex> v(3);
    std::vector<unsigned int> indices(3);
    std::vector<int> m(1, 0);

    v[0].vertices = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    v[0].tex_coords = glm::vec2(0.0f, 0.0f);
    indices[0] = 0;
    v[1].vertices = glm::vec4(0.0f, 0.5f, 0.0f, 1.0f);
    v[1].tex_coords = glm::vec2(0.0f, 1.0f);
    indices[1] = 1;
    v[2].vertices = glm::vec4(0.5f, 0.5f, 0.0f, 1.0f);
    v[2].tex_coords = glm::vec2(1.0f, 0.0f);
    indices[2] = 2;
    Mesh* mm = new Mesh(v, indices);
    mm->material_index = 0;

    std::vector<std::string> tex_paths(1, "res/tex1.jpg");

    d->loadStaticMesh(mm, 0);
    d->loadMaterials(tex_paths, 1);



    d->shader = new Shader("res/vertex_shader_hud.vert", "res/fragment_shader_hud.frag");


}

void HUD::update() {
    //nothing at the moment
}

void HUD::init() {

}

void HUD::draw() {

    d->shader->useProgram();
    d->draw(0);
    d->shader->unUseProgram();
}


