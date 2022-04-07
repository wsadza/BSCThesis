/*
    PrimitiveRenderer.cpp
    Purpose: Object renderer

    @author Igor Sadza
    @version 0.1 - 08/03/19
*/
#include "../renderers/PrimitiveRenderer.hpp"

unsigned PrimitiveRenderer::m_vao;
unsigned PrimitiveRenderer::m_vbo;

PrimitiveRenderer::PrimitiveRenderer() {
  
  float verticies[] = {
    0.0f, 0.0f, 0.0f, 0.0f, 
    1.0f, 0.0f, 1.0f, 0.0f, 
    0.0f, 1.0f, 0.0f, 1.0f, 

    1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 0.0f, 1.0f, 0.0f, 
    0.0f, 1.0f, 0.0f, 1.0f
  };

  glGenVertexArrays(1, &m_vao);
  glGenBuffers(1, &m_vbo);

  glBindVertexArray(m_vao);
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), &verticies, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)(0 * sizeof(float)));
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

}

PrimitiveRenderer &PrimitiveRenderer::initRenderer() {
  static PrimitiveRenderer primitiveRenderer;
  return primitiveRenderer;
}

void PrimitiveRenderer::renderPrimitive() {
  glBindVertexArray(m_vao);
    glDrawArrays(GL_TRIANGLES, 0, 6);
  glBindVertexArray(0); 
}