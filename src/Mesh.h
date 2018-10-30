//
// Created by sankeerth on 10/24/18.
//

#ifndef EFFGAMEENGINE_IMPORT3DOBJECT_H
#define EFFGAMEENGINE_IMPORT3DOBJECT_H

#include <glm/glm.hpp>
#include <vector>
#include <string>
#include <assimp/scene.h>

class Mesh {
private:
    const aiScene *scene;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<unsigned int> indices;

public:
    //textures needed to be added too
    explicit Mesh(const aiMesh* m);

    void getVertices();


};


#endif //EFFGAMEENGINE_IMPORT3DOBJECT_H
