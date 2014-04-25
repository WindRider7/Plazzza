//
// exception.cpp for exception.cpp in /home/li_w/rendu/cpp_nibbler
// 
// Made by 
// Login   <li_w@epitech.net>
// 
// Started on  Tue Apr  1 09:37:47 2014 
// Last update Tue Apr  1 09:37:48 2014 
//

# include <exception>
# include "exception.h"

coutExcept::coutExcept(std::string const& msg) throw() : _msg(msg)
{

}

coutExcept::~coutExcept() throw()
{

}

const char* coutExcept::what() const throw()
{
  return (this->_msg.c_str());
}

cerrExcept::cerrExcept(std::string const& msg) throw() : _msg(msg)
{

}

cerrExcept::~cerrExcept() throw()
{

}

const char* cerrExcept::what() const throw()
{
  return (this->_msg.c_str());
}
