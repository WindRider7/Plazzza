#ifndef PIZZA_H_
# define PIZZA_H_

#include <string>
#include <map>
#include "ingre.h"

class Pizza
{
 private:
  typePizza	type;
  taillePizza   size;
  std::map<int, int>	cooktimes;
  int		cooktime;
 public:
  Pizza(int, int);
  typePizza	get_type() const;
  taillePizza	get_size() const;
  int		get_cooktime() const;
  ~Pizza();
};

#endif
