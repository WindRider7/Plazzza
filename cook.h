#ifndef COOK_H_
# define COOK_H_

#include "exception.h"

class Cook
{
 private:
  bool	work;
  int	multiplier;
  int	time;
 public:
  Cook(int, int);
  ~Cook();
  bool get_work();
};

#endif
