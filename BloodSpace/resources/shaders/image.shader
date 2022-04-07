[VERTEX-SHADER]

#version 330 core

layout(location = 0) in vec4 t_verticies;

out vec2            m_textureCoords;

uniform mat4        t_projection;
uniform mat4        t_model;

void main() {

    gl_Position = t_projection * t_model * vec4(t_verticies.xy, 0.0f, 1.0f);
    m_textureCoords = t_verticies.zw;
}

// --------------------------------

[FRAGMENT-SHADER]

#version 330 core

out vec4            m_color;
in vec2             m_textureCoords;

uniform vec4        t_color = vec4(1.0f);
uniform sampler2D   t_sampler;

void main() {

    m_color = texture(t_sampler, m_textureCoords) * t_color;
    //m_color = t_color;
}