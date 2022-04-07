/*
    State.hpp
    Purpose: State.

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/
#include "../states/BaseState.hpp"

BaseState *BaseState::m_instance = 0;
BaseState::StateRegister BaseState::m_registry;

BaseState *BaseState::GetInstance() { 
    return m_instance; 
}

GLvoid BaseState::Register(const std::string &t_name, BaseState *t_state) {
  m_registry.insert(StateRegister::value_type(t_name, t_state));
  m_instance = t_state;
}

GLvoid BaseState::setInstance(const std::string &_name) {
  m_instance = LookUp(_name);
}

BaseState *BaseState::LookUp(const std::string &t_name) {
  for (auto &ite : m_registry) {
    if (ite.first == t_name) {
      return ite.second;
    }
  }
}