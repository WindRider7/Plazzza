#include "fifo.h"
#include <errno.h>
#include <string.h>
#include <cstdio>
#include <sstream>

bool Fifo::exists(const std::string& name)
{
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

Fifo::Fifo(int num, int set)
{
  std::string	tmp;
  std::ostringstream	os;
  std::string	dir("./fifos/");
  std::string error;

  if (set == 0)
    tmp.assign("a");
  else if (set == 1)
    tmp.assign("b");
  os << dir << num << tmp;
  if (exists(os.str().c_str()))
  {
    if (remove(os.str().c_str()) != 0)
    {
      error.append("rmfifo: ").append(strerror(errno));
      throw cerrExcept(error);
    }
  }
  if (mkfifo(os.str().c_str(), O_CREAT | O_RDWR | 0666) < 0)
  {
    error.append("mkfifo: ").append(strerror(errno));
    throw cerrExcept(error);
  }
  this->name.assign(os.str());
  //  this->f.open(this->name.c_str(), std::ostream::in | std::ostream::out);
  //  this->outfifo.open(this->name.c_str(), std::istream::out);
  this->fd = open(this->name.c_str(), O_RDWR);
}

Fifo::~Fifo()
{

}

Fifo	&Fifo::operator>>(std::string &msg)
{
  char	buf[100];

  memset(buf, 0, 100);
  read(this->fd, buf, sizeof(buf));
  msg.assign(buf);
  return (*this);
}	

Fifo	&Fifo::operator<<(std::string &msg)
{
  //this->f << msg;
  write(this->fd, msg.c_str(), msg.size());
  return (*this);
}
