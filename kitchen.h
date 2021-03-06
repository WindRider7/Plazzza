#ifndef KITCHEN_H_
# define KITCHEN_H_

#include "scopelock.h"
#include "mutex.h"
#include "pizza.h"
#include "exception.h"
#include "fifo.h"
#include <map>
#include <list>
#include "cook.h"

class Kitchen
{
 private:
  int			multiplier;
  int			ncooks;
  int			time;
  std::map<std::string, bool (*)(std::string&)> cmds;
  std::list<Cook>	cooks;
  std::map<std::string, Pizza* (*)(std::string)> instance_pizza;
  std::list<Pizza>	pizzas;
  bool    check_status(std::string &);
  bool    assign_pizza(std::string &);
  bool	  quit_process(std::string &);
public:
  Kitchen(int, int, int);
  bool	work(Fifo &fifoout, Fifo &fifoin);
  void  parse_order(std::string &order);
  ~Kitchen();
};

#endif
