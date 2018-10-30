//
// Created by sankeerth on 10/27/18.
//

#include "Renderable3D.h"


Renderable3D::Renderable3D( const aiScene* scene ) {

    for(int i = 0; i < scene->mNumMeshes; i++){
        all_renderable_meshes.push_back( new Mesh( scene->mMeshes[i] ) );
    }

}

Mesh* Renderable3D::get_mesh(int i){
    return all_renderable_meshes[i];
}