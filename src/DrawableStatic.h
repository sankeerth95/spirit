//
// Created by sankeerth on 10/27/18.
//

#ifndef EFFGAMEENGINE_RENDERABLE3D_H
#define EFFGAMEENGINE_RENDERABLE3D_H


#include <assimp/mesh.h>
#include <vector>
#include "Mesh.h"
#include "Texture.h"
#include "Shader.h"


// One scheme of drawing things.
// Draw and import all static meshes
// basically every object coming under a single shader

//Theres different drawables, but the one I'm focus

class DrawableStatic {

private:
    unsigned int *vao;
    unsigned int *vbo, *ibo;

    unsigned int *num_vertices, *num_indices;
    std::vector<Texture*> textures;
    void loadBuffers(void* data, unsigned int size, unsigned int buffer,
            unsigned int target);

public:

    Shader *shader;

    explicit DrawableStatic(int num_objects);
    ~DrawableStatic();

    std::vector<int> material_index;
    void loadStaticMesh(Mesh *m, int object_num);
    void draw(int object_num);

    // assimp specific!
    void loadMaterials(const aiScene* sc);

    // general loading of textures/materials
    void loadMaterials(std::vector<std::string> tex_path, int numMaterials);


    int num_buffers;
};

#endif //EFFGAMEENGINE_RENDERABLE3D_H
