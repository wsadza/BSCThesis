[VERTEX-SHADER]

#version 330 core

void main() {

    gl_Position = vec4(0.5f, 0.5f, 0.0f, 1.0f);
}

// --------------------------------

[FRAGMENT-SHADER]

#version 330 core

out vec4 m_color;

uniform vec4 t_color = vec4(1.0f);
uniform sampler2D t_sampler;

void main() {

    m_color = t_color;
}

// --------------------------------

[GEOMETRY-SHADER]

#version 330 core

layout (triangles) in;
layout (triangle_strip, max_vertices = 64) out;

uniform mat4 t_projection;
uniform mat4 t_model;

void main() {
    
    gl_Position = t_projection * t_model * (gl_in[0].gl_Position + vec4(0.0, -1.5, 0.0, 0.0f));
    EmitVertex();

    gl_Position =  t_projection * t_model * (gl_in[0].gl_Position + vec4(0.5, -0.08, 0.0, 0.0f));
    EmitVertex();

    gl_Position =  t_projection * t_model * (gl_in[0].gl_Position + vec4(-0.5, -0.08, 0.0, 0.0f));
    EmitVertex();

    for (int i = 0; i <= 45; i++) {

        float angle = 3.14 * 2.0 / 45 * i;

        vec4 offset = vec4(cos(angle), -sin(angle), 0.0, 0.0) / 2.0f;
        gl_Position =  t_projection * t_model * (gl_in[0].gl_Position + offset);
        EmitVertex();


        offset = vec4(cos(angle), sin(angle), 0.0, 0.0) / 2.0f;
        gl_Position =  t_projection * t_model * (gl_in[1].gl_Position + offset);
        EmitVertex();

    }
    EndPrimitive();
}

