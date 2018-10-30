//
// Created by sankeerth on 10/20/18.
//

#ifndef EFFGAMEENGINE_TEXTURE_H
#define EFFGAMEENGINE_TEXTURE_H


#include <string>
#include <GL/glew.h>

#include "../stb/stb_image.h"

class Texture {
private:
    unsigned int texture;
    stbi_uc *img;

public:
    explicit Texture(std::string file_path);
    void bind(unsigned int slot=0);
    void unbind();
    ~Texture();
};


#endif //EFFGAMEENGINE_TEXTURE_H
