#include "cook.h"

Cook::Cook(int _multiplier, int _time)
{
  this->multiplier = multiplier;
  this->time = _time;
  this->work = false;
}

Cook::~Cook()
{

}

bool	Cook::get_work()
{
  return this->work;
}
