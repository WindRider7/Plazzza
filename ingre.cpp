#include "ingre.h"

Ingre::Ingre()
{
  this->ingres["doe"] = 5;
  this->ingres["tomato"] = 5;
  this->ingres["Gruyere"] = 5;
  this->ingres["gruyere"] = 5;
  this->ingres["ham"] = 5;
  this->ingres["mushrooms"] = 5;
  this->ingres["Doe"] = 5;
  this->ingres["steak"] = 5;
  this->ingres["eggplant"] = 5;
  this->ingres["goat_cheese"] = 5;
  this->ingres["chief_love"] = 5;
  this->cost_ingres[Regina] = &Ingre::cost_regina;
  this->cost_ingres[Margarita] = &Ingre::cost_margarita;
  this->cost_ingres[Americaine] = &Ingre::cost_americana;
  this->cost_ingres[Fantasia] = &Ingre::cost_fantasia;
}

bool  Ingre::cost_margarita()
{
  this->ingres["doe"] -= 1 ;
  this->ingres["tomato"] -= 1;
  this->ingres["Gruyere"] -= 1;
}

bool  Ingre::cost_regina()
{
  this->ingres["doe"] -= 1 ;
  this->ingres["tomato"] -= 1;
  this->ingres["gruyere"] -= 1;
  this->ingres["ham"] -= 1;
  this->ingres["mushrooms"] -= 1;
}

bool  Ingre::cost_americana()
{
  this->ingres["Doe"] -= 1;
  this->ingres["gruyere"] -= 1;
  this->ingres["steak"] -= 1;
}

bool  Ingre::cost_fantasia()
{
  this->ingres["doe"] -= 1;
  this->ingres["tomato"] -= 1;
  this->ingres["eggplant"] -= 1;
  this->ingres["goat_cheese"] -= 1;
  this->ingres["chief_love"] -= 1;
}

bool  Ingre::cost_ingre(typePizza type)
{
  (this->*cost_ingres[type])();
}

Ingre::~Ingre()
{

}
