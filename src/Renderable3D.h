//
// Created by sankeerth on 10/27/18.
//

#ifndef EFFGAMEENGINE_RENDERABLE3D_H
#define EFFGAMEENGINE_RENDERABLE3D_H


#include "Mesh.h"

class Renderable3D {

private:
    std::vector<Mesh *> all_renderable_meshes;

public:
    explicit Renderable3D(const aiScene *scene);
    Mesh *get_mesh(int i);

};


#endif //EFFGAMEENGINE_RENDERABLE3D_H
