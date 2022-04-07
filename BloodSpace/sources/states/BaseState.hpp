/*
    State.hpp
    Purpose: State.

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/
#ifndef BASE_STATE_HPP
#define BASE_STATE_HPP

#include "../utils/CommonIncludes.hpp"

class BaseState {
private:
  typedef std::map<std::string, BaseState*> StateRegister;
  static StateRegister m_registry;
  static BaseState *m_instance;

public:
  static BaseState *GetInstance();
  static GLvoid Register(const std::string &_name, BaseState *t_state);
  static GLvoid setInstance(const std::string &_name);

  virtual GLvoid stateRender() = 0;
  virtual GLvoid stateLogic()  = 0;
  virtual GLvoid stateBackground() = 0;
  
protected:
  static BaseState *LookUp(const std::string &_name);
};

#endif //BASE_STATE_HPP