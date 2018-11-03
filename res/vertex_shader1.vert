#version 430 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 in_tex_coords;

out vec2 tex_coords;


uniform mat4 u_mvp;


void main(void){
    gl_Position = u_mvp*vec4(position, 1.0f);
    tex_coords = in_tex_coords;
}

