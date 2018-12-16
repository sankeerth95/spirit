//
// Created by sankeerth on 12/16/18.
//

#include <iostream>
#include "Text.h"


// Just static text for now.
Text::Text(std::string msg): message(msg) {
}

void Text::setText(std::string msg) {
    message = msg;
}

void Text::generateTextMap(float x, float y, float size) {

    for(unsigned int i = 0; i < message.length(); i++){
        Vertex v1, v2, v3, v4;
        v1.vertices = glm::vec4(x+i*size, y, 0.0f, 1.0f);
        v1.tex_coords = glm::vec2((message[i]%16)/16.0f, 1 - (message[i]/16)/16.0f - 1/16.0f);
        std::cout << v1.tex_coords.x << "," << v1.tex_coords.y << std::endl;
        v2.vertices = glm::vec4(x+i*size+size, y, 0.0f, 1.0f);
        v2.tex_coords = glm::vec2((message[i]%16)/16.0f + 1/16.0f, 1- (message[i]/16)/16.0f - 1/16.0f);

        v3.vertices = glm::vec4(x+i*size+size, y+size, 0.0f, 1.0f);
        v3.tex_coords = glm::vec2((message[i]%16)/16.0f + 1/16.0f, 1- (message[i]/16)/16.0f);

        v4.vertices = glm::vec4(x+i*size, y+size, 0.0f, 1.0f);
        v4.tex_coords = glm::vec2((message[i]%16)/16.0f, 1- (message[i]/16)/16.0f);

        vv.push_back(v1);
        vv.push_back(v2);
        vv.push_back(v3);
        vv.push_back(v4);

        vv_indices.push_back(4*i+0);
        vv_indices.push_back(4*i+1);
        vv_indices.push_back(4*i+2);

        vv_indices.push_back(4*i+0);
        vv_indices.push_back(4*i+3);
        vv_indices.push_back(4*i+2);
    }

}
