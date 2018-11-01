//
// Created by sankeerth on 11/1/18.
//

#ifndef SPIRIT_VERTECSPEC_H
#define SPIRIT_VERTECSPEC_H

#include <glm/glm.hpp>

typedef struct VertexSpec{
    glm::vec3 vertices;
    glm::vec3 normals;
    glm::vec2 tex_coords;
} Vertex;

#endif //SPIRIT_VERTECSPEC_H
