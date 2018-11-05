//
// Created by sankeerth on 10/27/18.
//

#include <GL/glew.h>
#include <iostream>
#include "Drawable.h"


Drawable::Drawable() {

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ibo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(sizeof(glm::vec3)));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(2*sizeof(glm::vec3)));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

void Drawable::loadBuffers(void* data, unsigned int size, unsigned int buffer,
        unsigned int target=GL_ARRAY_BUFFER){
    glBindBuffer(target, buffer);
    glBufferData(target, size, data, GL_STATIC_DRAW);
    glBindBuffer(target, 0);
}

void Drawable::update(Mesh* m){     //poinnum_verticester is const? shows some error if so

    glBindVertexArray(vao);

    num_vertices = m->getNumVertices();
    num_indices = m->getNumIndices();

    loadBuffers( &(m->getPoints()[0]), num_vertices*sizeof(Vertex), vbo, GL_ARRAY_BUFFER);
    loadBuffers( &(m->getIndices()[0]), num_indices*sizeof(unsigned int), ibo, GL_ELEMENT_ARRAY_BUFFER);

    glBindVertexArray(0);
}

void Drawable::draw(){

    //TODO: just bind every buffer before draw call
    glBindVertexArray(vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo); //element buffer has to be bound!!!
    glDrawElements(GL_TRIANGLES, num_indices, GL_UNSIGNED_INT, nullptr);

    glBindVertexArray(0);

}

Drawable::~Drawable() {
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);

    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ibo);
    glDeleteVertexArrays(1, &vao);
};