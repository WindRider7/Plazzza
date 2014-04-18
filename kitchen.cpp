#include "kitchen.h"

Kitchen::Kitchen(int _multiplier, int _cooks, int _time)
{
  int	i;

  this->multiplier = _multiplier;
  this->ncooks = _cooks;
  this->time = _time;
  i = 0;
  while (i < _cooks)
    {
      Cook	*cook = new Cook(_multiplier, _time);
      this->cooks.push_back(cook);
      i = i + 1;
    }
}

/*void	Kitchen::check_status(std::string &order)
{

}*/

bool	Kitchen::assign_pizza(std::string &order)
{
  /*  std::list<Cook*>::iterator it;

  it = this->cooks.begin();
  while (it != this->cooks.end())
    {
      if ((*it)->get_work == false)
	{
	  (*it)->cook_pizza(order);
	  (*it)->take_ingre(this->ingre);
	  return (true);
	}
      it++;
    }
    return (false);*/
}
/*
void	Kitchen::quit_process(std::string &order)
{

}
*/
bool	Kitchen::work(Fifo *fifoin, Fifo *fifoout)
{
  std::string	res;

  while (1)
    {
      *fifoin >> res;
      /* if (!res.empty())
	{
	  if (this->assign_pizza(res) == false)
	    *fifoout << "erro";
	  else
	    *fifoout << "succ";
	    }*/
    }
}

Kitchen::~Kitchen()
{
  
}
