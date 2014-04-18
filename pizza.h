#ifndef PIZZA_H_
# define PIZZA_H_

#include <string>

typedef enum	TypePizza
  {
    Regina = 1,
    Margarita = 2,
    Americaine = 4,
    Fantasia = 8
  }	typePizza;

typedef enum	TaillePizza
  {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
  }		taillePizza;

class Pizza
{
 private:
  typePizza  type;
  taillePizza size;
  std::string	number;
 public:
  Pizza(typePizza, taillePizza, std::string &);
  ~Pizza();
};

#endif
