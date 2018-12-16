//
// Created by sankeerth on 12/15/18.
//

#include <iostream>
#include "HUD.h"
#include "Text.h"

HUD::HUD() {

    d = new DrawableStatic(1);
    numMeshes = 1;

    Text text(" ");
    text.generateTextMap(0, 0, 0.1);
    std::vector<Vertex> v = text.vv;// = text.generateTextMap();
    std::vector<unsigned int> indices = text.vv_indices ;
    std::vector<int> m(1, 0);




    Mesh* mm = new Mesh(v, indices);
    mm->material_index = 0;

    std::vector<std::string> tex_paths(1, "res/cells.png");

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

