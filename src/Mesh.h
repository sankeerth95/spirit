//
// Created by sankeerth on 10/24/18.
//

#ifndef EFFGAMEENGINE_IMPORT3DOBJECT_H
#define EFFGAMEENGINE_IMPORT3DOBJECT_H

#include <glm/glm.hpp>
#include <vector>
#include <string>
#include <assimp/scene.h>
#include "VertecSpec.h"

class Mesh {
private:
    std::vector<Vertex> points;
    std::vector<unsigned int> indices;
    unsigned int num_vertices, num_indices;

public:
    int material_index;

    //textures needed to be added too
    explicit Mesh(const aiMesh *m, glm::mat4 global_transform);
    Mesh(std::vector<Vertex> v, std::vector<unsigned int> indices);

    //getter methods
    std::vector<Vertex> getPoints();
    unsigned int getNumVertices();
    unsigned int getNumIndices();
    std::vector<unsigned int> getIndices();

};


#endif //EFFGAMEENGINE_IMPORT3DOBJECT_H
