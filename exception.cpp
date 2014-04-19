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

myException::myException(std::string const& msg) throw() : _msg(msg)
{

}

myException::~myException() throw()
{

}

const char* myException::what() const throw()
{
  return (this->_msg.c_str());
}
