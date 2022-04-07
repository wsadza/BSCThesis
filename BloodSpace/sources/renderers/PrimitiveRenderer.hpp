/*
    PrimitiveRenderer.cpp
    Purpose: Object renderer

    @author Igor Sadza
    @version 0.1 - 08/03/19
*/

#ifndef PRIMITIVE_RENDERER_HPP
#define PRIMITIVE_RENDERER_HPP

#include "../utils/CommonIncludes.hpp"
#include "../pieces/Primitive.hpp"

class PrimitiveRenderer {
private:
  PrimitiveRenderer();
  static unsigned m_vao;
  static unsigned m_vbo;

public:
  static PrimitiveRenderer &initRenderer();
  static void renderPrimitive();
};

#endif // PRIMITIVE_RENDERER_HPP