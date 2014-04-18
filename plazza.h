#ifndef PLAZZA_H_
# define PLAZZA_H_

#include <string>
#include <list>
#include "kitchen.h"
#include "parse.h"
#include <iostream>
#include "fifo.h"

class Plazza
{
 private:
  int		multiplier;
  int		cooks;
  int		time;
  Parse		*parse;
  int		num;
  int		pid;
  std::list<Fifo*>	fifosin;
  std::list<Fifo*>	fifosout;
 public:
  Plazza(int, int, int);
  ~Plazza();
  void  reception();
  void  assign_to_kitchen(std::string *pizza);
};

#endif
