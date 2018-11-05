#version 430 core

layout(location = 0) out vec4 color;

in vec2 tex_coords;
uniform sampler2D tex1_texture;

void main(void){
    color = texture(tex1_texture, tex_coords);
//    color = vec4(1.0f, 1.0f, 0.0f, 1.0f);
}
