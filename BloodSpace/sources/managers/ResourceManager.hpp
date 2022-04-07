/**
 *  File: ResourceManager.hpp
 *  Purpose:    
 * 
 *  @author: Igor Sadza
 *  @version 1.0 - 31/01/19 
*/

#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include "../utils/CommonIncludes.hpp"

template <class Type>
class ResourceManager {
private:
    // Container.
    static std::vector<Type> m_registry;
    // Search object by type for registry purpose.
    static bool search(Type t_object);
public:
    // Search object by object.
    static bool searchObject(Type t_object);
    // Search object by name for user purpose.
    static bool searchObject(const std::string& t_objectName);

    // Register object in index.
    static void registerObject(const Type &t_object);
    // Get all object with this same type.
    static std::vector<Type> getObjects();
    // Get single object.
    static Type getObject(const std::string& t_objectName);
};

#include "../managers/ResourceManager.hxx"

#endif // RESOURCE_MANAGER_HPP