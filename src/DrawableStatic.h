//
// Created by sankeerth on 10/27/18.
//

#ifndef EFFGAMEENGINE_RENDERABLE3D_H
#define EFFGAMEENGINE_RENDERABLE3D_H


#include <assimp/mesh.h>
#include <vector>
#include "Mesh.h"
#include "Texture.h"


// One scheme of drawing things.
class DrawableStatic {

private:
    unsigned int *vao;
    unsigned int *vbo, *ibo;

    unsigned int *num_vertices, *num_indices;
    std::vector<Texture*> textures;
    void loadBuffers(void* data, unsigned int size, unsigned int buffer,
            unsigned int target);

public:
    explicit DrawableStatic(int num_objects);
    ~DrawableStatic();

    void loadStaticMesh(Mesh *m, int object_num);
    void draw(int object_num);

    void loadMaterials(const aiScene* sc);

    int num_buffers;
    std::vector<int> material_index;
};


#endif //EFFGAMEENGINE_RENDERABLE3D_H