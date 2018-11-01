//
// Created by sankeerth on 10/27/18.
//

#ifndef EFFGAMEENGINE_RENDERABLE3D_H
#define EFFGAMEENGINE_RENDERABLE3D_H


#include <assimp/mesh.h>
#include <vector>
#include "Mesh.h"

class Drawable {

private:
    unsigned int vao, vbo, ibo;

    unsigned int num_vertices, num_indices;
    void loadBuffers(void* data, unsigned int size, unsigned int buffer,
            unsigned int target);

public:
    explicit Drawable();
    ~Drawable();

    void update(Mesh* m);
    void draw();

};


#endif //EFFGAMEENGINE_RENDERABLE3D_H
