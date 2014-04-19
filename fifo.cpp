#include "fifo.h"
#include <string.h>

Fifo::Fifo(int num, int set)
{
  std::string	tmp;
  std::ostringstream	os;
  std::string	dir("./fifos/");

  if (set == 0)
    tmp.assign("a");
  else if (set == 1)
    tmp.assign("b");
  os << dir << num << tmp;
  if (mkfifo(os.str().c_str(), O_CREAT | O_RDWR | 0666) < 0)
    throw myException("fifo create error");
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
