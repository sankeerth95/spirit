#version 430 core

layout(location = 0) in vec3 position;


out vec2 tex_coords;


void main(void){
    gl_Position = vec4(position, 10.0f);
    tex_coords = in_tex_coords;
}

