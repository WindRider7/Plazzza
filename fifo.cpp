#include "fifo.h"

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
    std::cout << "fifo creat error" << std::endl;
  this->name.assign(os.str());
  this->f.open(this->name.c_str(), std::ostream::in | std::ostream::out);
  //  this->outfifo.open(this->name.c_str(), std::istream::out);
  std::cout << "99999999999" << std::endl;
}

Fifo::~Fifo()
{
  
}

Fifo	&Fifo::operator>>(std::string &msg)
{
  std::cout << "operator1 >>" << std::endl;
  this->f >> msg;
  std::cout << "operator2 >>" << std::endl;
  return (*this);
}	

Fifo	&Fifo::operator<<(std::string &msg)
{
  std::cout << "operator1 >> " << std::endl;
  this->f << msg;
  std::cout << "operator2 >> " << std::endl;
  return (*this);
}
