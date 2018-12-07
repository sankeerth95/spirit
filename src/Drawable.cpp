//
// Created by sankeerth on 10/27/18.
//

#include <GL/glew.h>
#include <iostream>
#include "Drawable.h"


Drawable::Drawable(int num_objects) {

    num_buffers = num_objects;

    vao = new unsigned int[num_buffers];
    vbo = new unsigned int[num_buffers];
    ibo = new unsigned int[num_buffers];


    num_vertices = new unsigned int[num_objects];
    num_indices = new unsigned int[num_objects];

    material_index.resize(num_objects);

    glGenVertexArrays(num_objects, vao);
    glGenBuffers(num_objects, vbo);
    glGenBuffers(num_objects, ibo);

    for(int i = 0; i < num_objects; i++) {
        glBindVertexArray(vao[i]);
        glBindBuffer(GL_ARRAY_BUFFER, vbo[i]);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) (sizeof(glm::vec4)));

        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) (sizeof(glm::vec4) + sizeof(glm::vec3)));
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


}

void Drawable::loadBuffers(void* data, unsigned int size, unsigned int buffer,
        unsigned int target=GL_ARRAY_BUFFER){
    glBindBuffer(target, buffer);
    glBufferData(target, size, data, GL_STATIC_DRAW);
    glBindBuffer(target, 0);
}

void Drawable::update(Mesh *m, int object_num) {     //poinnum_verticester is const? shows some error if so

    glBindVertexArray(vao[object_num]);

    num_vertices[object_num] = m->getNumVertices();
    num_indices[object_num] = m->getNumIndices();

    material_index[object_num] = m->material_index;
    loadBuffers( &(m->getPoints()[0]), num_vertices[object_num]*sizeof(Vertex), vbo[object_num], GL_ARRAY_BUFFER);
    loadBuffers( &(m->getIndices()[0]), num_indices[object_num]*sizeof(unsigned int), ibo[object_num], GL_ELEMENT_ARRAY_BUFFER);

    glBindVertexArray(0);
}

void Drawable::draw(int object_num) {

    glBindVertexArray(vao[object_num]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo[object_num]); //element buffer has to be bound!!!

    textures[material_index[object_num]]->bind(0);
    glDrawElements(GL_TRIANGLES, num_indices[object_num], GL_UNSIGNED_INT, nullptr);

 //   glBindVertexArray(0);
}


void Drawable::loadMaterials(const aiScene* sc) {

    //single embedded diffuse texture per material handled, no colors at the moment.

    /* getTexture Filenames and Numb of Textures */
    int num_materials = sc->mNumMaterials;
    textures.resize(num_materials);
    for (unsigned int m = 0; m < num_materials; m++) {
        unsigned int texIndex = 0;
        aiReturn texFound = AI_SUCCESS;
        aiString path;    // filename
        if (sc->mMaterials[m]->GetTextureCount(aiTextureType_DIFFUSE) > 0) {
            texFound = sc->mMaterials[m]->GetTexture(aiTextureType_DIFFUSE, texIndex, &path);

            if (texFound == AI_SUCCESS) {
                textures[m] = new Texture(path.C_Str());
            } else {
                textures[m] = new Texture("res/tex1.jpg");
            }
        }
        //handle color materials here boi
//        else if (sc->mMaterials[m]->)
    }
}


Drawable::~Drawable() {
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);

    glDeleteBuffers(num_buffers, vbo);
    glDeleteBuffers(num_buffers, ibo);
    glDeleteVertexArrays(num_buffers, vao);

//    delete textures;
}