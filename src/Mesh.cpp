//
// Created by sankeerth on 10/24/18.
//

#include "Mesh.h"
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <iostream>

Mesh::Mesh(const aiMesh* m) {

    //populate vertices and shit
    num_vertices = m->mNumVertices;
    num_indices = m->mNumFaces * 3;

    points.resize(num_vertices);
    indices.resize(num_indices);

    material_index = m->mMaterialIndex;

    for (int i = 0; i < num_vertices; i++) {
        points[i].vertices = glm::vec3(m->mVertices[i].x, m->mVertices[i].y, m->mVertices[i].z);
        points[i].normals = glm::vec3(m->mNormals[i].x, m->mNormals[i].y, m->mNormals[i].z);
//        points[i].tex_coords = glm::vec2(m->mTextureCoords[0][i].x,
//                                       m->mTextureCoords[0][i].y);
    }
    for (int i = 0; i < num_indices; i+=3){  // assuming triangle rendering
        assert(m->mFaces[i/3].mNumIndices == 3);
        indices[i] = m->mFaces[i/3].mIndices[0];
        indices[i+1] = m->mFaces[i/3].mIndices[1];
        indices[i+2] = m->mFaces[i/3].mIndices[2];
    }
}

//TODO: check the return type: is it creating a copy again?
std::vector<Vertex> Mesh::getPoints() {
    return points;
}

std::vector<unsigned int> Mesh::getIndices() {
    return indices;
}

unsigned int Mesh::getNumVertices() {
    return num_vertices;
}

unsigned int Mesh::getNumIndices() {
    return num_indices;
}

