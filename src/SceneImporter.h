//
// Created by sankeerth on 10/26/18.
//

#ifndef EFFGAMEENGINE_SCENEIMPORTER_H
#define EFFGAMEENGINE_SCENEIMPORTER_H


#include <string>
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include "Mesh.h"

class SceneImporter {

private:
    const aiScene *scene;
    Assimp::Importer importer;

public:
    explicit SceneImporter(const std::string& filename);
    ~SceneImporter();

    const aiScene* getScene();

};

#endif //EFFGAMEENGINE_SCENEIMPORTER_H
