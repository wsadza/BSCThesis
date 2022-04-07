/**
 *  File: ResourceManager.hxx
 *  Purpose:    
 * 
 *  @author: Igor Sadza
 *  @version 1.0 - 01/01/19 
*/

#include "../managers/ResourceManager.hpp"

template <class Type>
std::vector<Type> ResourceManager<Type>::m_registry;

template <class Type> 
bool ResourceManager<Type>::search(Type t_object) {
    
    for (auto& ite: m_registry) {
        if (ite.getName() == t_object.getName()) {
            return true;
        }
    }
    return false;
}

template <class Type> 
bool ResourceManager<Type>::searchObject(const std::string& t_objectName) {
    
    for (auto& ite: m_registry) {
        if (ite.getName() == t_objectName) {
            return true;
        }
    }
    return false;
}

template <class Type> 
bool ResourceManager<Type>::searchObject(Type t_object) {
    
    for (auto& ite: m_registry) {
        if (ite.getName() == t_object.getName()) {
            return true;
        }
    }
    return false;
}

template <class Type>
void ResourceManager<Type>::registerObject(const Type &t_object) {
    if (!search(t_object)) {
        m_registry.push_back(t_object);
    }
}

template <class Type> 
std::vector<Type> ResourceManager<Type>::getObjects() {
    return m_registry;
}

template <class Type>
Type ResourceManager<Type>::getObject(const std::string& t_objectName) {
    for(auto&ite: m_registry) {
        if (ite.getName() == t_objectName) {
            return ite;
        }
    }
}