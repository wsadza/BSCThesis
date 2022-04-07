[VERTEX-SHADER]

#version 330 core

layout (location = 0) in vec4 t_verticies;

uniform mat4 t_projection;

out vec2 m_textCoords;

void main() {

    gl_Position = t_projection * vec4(t_verticies.xy, 0.0f, 1.0f);
    m_textCoords = t_verticies.zw;
}  

// --------------------------------

[FRAGMENT-SHADER]

#version 330 core

out vec4 out_Color;

uniform sampler2D t_sampler;
uniform vec4 t_color = vec4(1.0f);

in vec2 m_textCoords;

void main(){
    vec4 sampled = vec4(1.0f, 1.0f, 1.0f, texture(t_sampler, vec2(m_textCoords)).r);
    out_Color = t_color * sampled;    
}  