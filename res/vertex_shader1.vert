#version 430 core

layout(location = 0) in vec2 position;
layout(location = 1) in vec2 in_tex_coords;

out vec2 tex_coords;

void main(void){
    gl_Position = vec4(position, -0.5f, 1.0f);
    tex_coords = in_tex_coords;
}

