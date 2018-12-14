//
// Created by sankeerth on 11/2/18.
//

#ifndef SPIRIT_SHADER_H
#define SPIRIT_SHADER_H


#include <string>

class Shader {

private:
    unsigned int fragment_shader, vertex_shader, program;
    std::string parseShader(const std::string& path);
    unsigned int create_shader(unsigned int type, const std::string &src);

public:
    Shader(const std::string& vs_path, const std::string& fs_path );
    void useProgram();
    void unUseProgram();

    unsigned int getVertexShader();
    unsigned int getFragmentShader();
    unsigned int getProgram();

};


#endif //SPIRIT_SHADER_H
