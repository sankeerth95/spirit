//
// Created by sankeerth on 10/26/18.
//

#include "SceneImporter.h"
#include "Mesh.h"
#include <assimp/postprocess.h>

SceneImporter::SceneImporter(const std::string &filename) {

    scene = importer.ReadFile(filename.c_str(),
                              aiProcess_Triangulate |
                              aiProcess_CalcTangentSpace |
                              aiProcess_JoinIdenticalVertices
                              );
}

const aiScene* SceneImporter::getScene(){
    return scene;
}


const aiMesh *SceneImporter::getMesh(unsigned int i) {
    //TODO: WTF is this
    return nullptr;
}


SceneImporter::~SceneImporter(){
    //TODO: fill this up
}
