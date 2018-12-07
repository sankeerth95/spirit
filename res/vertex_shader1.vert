#version 430 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 in_tex_coords;

out vec3 position_;
out vec3 normal_;

out vec2 tex_coords;
uniform mat4 u_mvp;


void main(void){

    gl_Position = u_mvp*position;
    tex_coords = in_tex_coords;

    position_ = position.xyz/position.w;
    normal_ = normal;
}

