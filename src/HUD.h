//
// Created by sankeerth on 12/15/18.
//

#ifndef SPIRIT_HUD_H
#define SPIRIT_HUD_H


#include <glm/ext.hpp>
#include "DrawableStatic.h"

class HUD {
    public:

    DrawableStatic* d;
    int numMeshes;



    std::vector<Texture*> textures;

    HUD();

    void init();

    void update();
    void draw();

};


#endif //SPIRIT_HUD_H
