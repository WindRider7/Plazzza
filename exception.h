/*
** exception.h for exception.h in /home/balang_b/Documents/nibbler
** 
** Made by balang_b
** Login   <balang_b@epitech.net>
** 
** Started on  Sun Apr  6 14:04:55 2014 balang_b
** Last update Fri Apr 18 13:01:00 2014 
*/

#ifndef MY_EXCEPTION_H_
# define MY_EXCEPTION_H_

# include <string>
# include <exception>

class	coutExcept
{
public:
  coutExcept(std::string const& msg) throw();
  virtual	~coutExcept() throw();
  virtual const char* what() const throw();
private:
  std::string _msg;
};

class cerrExcept
{
public:
  cerrExcept(std::string const& msg) throw();
  virtual ~cerrExcept() throw();
  virtual const char* what() const throw();
private:
  std::string _msg;
};

#endif /* !EXCEPTION_H_ */
