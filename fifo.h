#ifndef FIFO_H_
# define FIFO_H_

#include "exception.h"
#include <string>
#include <fcntl.h>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <fstream>

class Fifo
{
 private:
  std::string		name;
  //  std::fstream		f;
  // std::ifstream		infifo;
  // std::ofstream		outfifo;
  int	fd;
 public:
  Fifo(int num, int set);
  ~Fifo();
  Fifo& operator>>(std::string &msg);
  Fifo& operator<<(std::string &msg);
};

#endif
