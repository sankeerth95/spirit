//
// Created by sankeerth on 12/16/18.
//

#ifndef SPIRIT_TEXT_H
#define SPIRIT_TEXT_H


#include <string>
#include <vector>
#include "VertecSpec.h"

class Text {

public:

    std::string message;
    std::vector<Vertex> vv;
    std::vector<unsigned int> vv_indices;



    explicit Text(std::string msg);

    void setText(std::string msg);
    void generateTextMap(float x, float y, float size);

};


#endif //SPIRIT_TEXT_H
