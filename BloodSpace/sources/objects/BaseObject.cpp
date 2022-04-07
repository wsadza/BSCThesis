/*
    Base_Object.cpp
    Purpose: -

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/
#include "../objects/BaseObject.hpp"
#include "../renderers/PrimitiveRenderer.hpp"
#include "../renderers/TextRenderer.hpp"
#include "../managers/ResourceManager.hpp"

// ! BaseObject class.



BaseObject::BaseObject() 
    : m_image(nullptr)
    , m_shader(nullptr)
    , m_text(nullptr)
    , m_primitive(nullptr){

}

GLvoid BaseObject::objectRender() {
    
    if (m_image) {
        m_image->use();        
    }

    if (m_shader) {
        m_shader->use();
    }

    if (m_primitive) {
        glm::mat4 modelMatrix;        
        modelMatrix = glm::translate(modelMatrix, glm::vec3(m_primitive->getPosition(), 0.0f));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(m_primitive->getSize(), 0.0f));
        
        m_shader->sendVariable("t_model", modelMatrix);
        m_shader->sendVariable("t_color", m_primitive->getColor());        
        PrimitiveRenderer::renderPrimitive();        
    }

    if(m_text) {
        TextRenderer::renderText(*m_text);
    }
}

// ! Setters.

GLvoid BaseObject::setPrimitive(glm::vec2 t_size, glm::vec2 t_position, glm::vec4 t_color) {
        m_primitive = new Primitive();
        m_primitive->setSize(t_size);
        m_primitive->setColor(t_color);
        m_primitive->setPosition(t_position);
}
GLvoid BaseObject::setImage(const std::string &t_pathImage) {

    if(!ResourceManager<Image>::searchObject(t_pathImage)) {
        m_image = new Image(t_pathImage);        
    }else {
        m_image = new Image(); 
        *m_image = ResourceManager<Image>::getObject(t_pathImage);
    }

    if(!m_primitive) {
        m_primitive = new Primitive();
        m_primitive->getSize() = m_image->getSize();
        m_primitive->setColor(1.0f);
        m_primitive->setPosition(0.0f);
    } else {
        m_primitive->getSize() = m_image->getSize();
    }
}
GLvoid BaseObject::setShader(const std::string &t_pathShader) {
    m_shader = new Shader(t_pathShader);    

}
GLvoid BaseObject::setText(const std::string &t_textRender) {
    m_text = new Text(t_textRender, *m_primitive);
}
GLvoid BaseObject::saveObject() {
    m_savedObject = new BaseObject();
    *m_savedObject = *this;
}
GLvoid BaseObject::restoreObject() {
    *this = *m_savedObject;
}
// ! Getters.

Primitive &BaseObject::getPrimitive() {
    return *m_primitive;
}
Image &BaseObject::getImage() {
    return *m_image;
}
Text &BaseObject::getText() {
    return *m_text;
}
Shader &BaseObject::getShader() {
    return *m_shader;
}