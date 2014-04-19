#ifndef INGRE_H_
# define INGRE_H_

#include <map>
#include "exception.h"

typedef enum    TypePizza
  {
    Regina = 1,
    Margarita = 2,
    Americaine = 4,
    Fantasia = 8
  }             typePizza;

typedef enum    TaillePizza
  {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
  }             taillePizza;

class	Ingre
{
 private:
  std::map<std::string, int>	ingres;
  std::map<typePizza, bool (Ingre::*)()> cost_ingres;
  bool	cost_margarita();
  bool  cost_regina(); 
  bool  cost_americana();
  bool  cost_fantasia();
 public:
  Ingre();
  ~Ingre();
  bool	cost_ingre(typePizza);
};

#endif
