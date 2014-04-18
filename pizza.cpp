#include "pizza.h"

Pizza::Pizza(TypePizza _type, TaillePizza _size, std::string &_number)
{
  this->type = _type;
  this->size = _size;
  this->number = _number;
}

Pizza::~Pizza()
{

}
