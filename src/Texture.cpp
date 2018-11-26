//
// Created by sankeerth on 10/20/18.
//

#include <iostream>
#include "Texture.h"


Texture::Texture(std::string file_path){
    int w, h, comp;

    stbi_set_flip_vertically_on_load(1);
    img = stbi_load(file_path.c_str(), &w, &h, &comp, STBI_rgb_alpha);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, img);
    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(img);
}

void Texture::bind(int slot){

    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, texture);
}

void Texture::unbind(){
//    glActiveTexture(GL_TEXTURE0 + slo);
//    glBindTexture(GL_TEXTURE_2D, 0);
//      go to slot with glActiveTexture, and clear it
}

Texture::~Texture(){
    unbind();
    glDeleteTextures(1, &texture);
}