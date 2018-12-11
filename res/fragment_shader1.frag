#version 430 core

layout(location = 0) out vec4 color;

layout(location = 0) in vec3 position_;
layout(location = 1) in vec3 normal_;

in vec2 tex_coords;
uniform sampler2D tex1_texture;

void main(void){
    float ambient = 0.4f;
    float diffuse = max(abs(1.0*dot(normalize(normal_), normalize(position_))), .2);
    vec4 color1 = (ambient+diffuse)*texture(tex1_texture, tex_coords);
    color = vec4(color1.xyz,  1.0f);
//    color = vec4(1.0f, 1.0f, 0.0f, 1.0f);
}
