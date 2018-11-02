//
// Created by sankeerth on 11/2/18.
//

#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include "Shader.h"



std::string Shader::parseShader(const std::string& path){

    std::ifstream f(path);
    std::stringstream ss;
    ss << f.rdbuf();

    return ss.str();
}

unsigned int Shader::create_shader(unsigned int type, const std::string &src){

    const char* cc = &src.c_str()[0];

    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &cc, nullptr);
    glCompileShader(shader);

//    glGetShaderiv(shader, GL_COMPILE_STATUS, )

    return shader;
}

Shader::Shader(const std::string &vs_path, const std::string &fs_path) {

    vertex_shader = create_shader(GL_VERTEX_SHADER, parseShader(vs_path));
    fragment_shader = create_shader(GL_FRAGMENT_SHADER, parseShader(fs_path));
    program = glCreateProgram();

    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
}

void Shader::useProgram() {
    glUseProgram(program);
}

unsigned int Shader::getVertexShader() {
    return vertex_shader;
}

unsigned int Shader::getFragmentShader() {
    return fragment_shader;
}

unsigned int Shader::getProgram() {
    return program;
}

