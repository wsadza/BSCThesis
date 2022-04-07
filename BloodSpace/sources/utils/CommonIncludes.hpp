/*
    CommonIncludes.hpp
    Purpose: File to attach includes.

    @author Igor Sadza
    @version 0.1 - 06/03/19
*/

#pragma ONCE
#ifndef COMMON_INCLUDES_HPP
#define COMMON_INCLUDES_HPP

// Legacy headers
#include <iostream>
#include <vector>
#include <map>
#include <typeindex>
#include <typeinfo>
#include <sstream>

// Font loader
#include <ft2build.h>
#include FT_FREETYPE_H

// OpenGL loader
#include "dependencies/glad.h"
// Image loader
#include "dependencies/stb_image.h"

// OpenGL surface
#include <GLFW/glfw3.h>

// OpenGL mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#endif //COMMON_INCLUDES_HPP