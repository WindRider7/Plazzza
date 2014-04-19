#include "pizza.h"

Pizza::Pizza(int  _type, int _size)
{
  this->type = static_cast<typePizza>(_type);  
  this->size = static_cast<taillePizza>(_size);
  this->cooktimes[1] = 1;
  this->cooktimes[2] = 2;
  this->cooktimes[4] = 2;
  this->cooktimes[8] = 4;
  this->cooktime = this->cooktimes[_type];
}

typePizza     Pizza::get_type() const
{
  return this->type;
}

taillePizza   Pizza::get_size() const
{
  return this->size;
}

int           Pizza::get_cooktime() const
{
  return this->cooktime;
}

Pizza::~Pizza()
{

}
