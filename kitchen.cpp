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
      Cook	cook(_multiplier, _time);
      this->cooks.push_back(cook);
      i = i + 1;
    }
}

bool	Kitchen::check_status(std::string &order)
{

}

bool	Kitchen::assign_pizza(std::string &order)
{
  std::list<Cook>::iterator it;

  it = this->cooks.begin();
  while (it != this->cooks.end())
    {
      if ((*it).get_work() == false)
	{
	  // (*it).cook_pizza(order);
	  //	  (*it).take_ingre(this->ingre);
	  return (true);
	}
      it++;
    }
  return (false);
}

bool	Kitchen::quit_process(std::string &order)
{

}

void	Kitchen::parse_order(std::string &order)
{
  

}

bool	Kitchen::work(Fifo &fifoin, Fifo &fifoout)
{
  std::string	res;
  std::string	msg;

  while (1)
    {
      fifoin >> res;
      if (!res.empty())
	{
	  if (this->assign_pizza(res) == false)
	    {
	      msg.assign("erro");
	      fifoout << msg;
	    }
	  else
	    {
	      msg.assign("succ");
	      fifoout << msg;
	    }
	}
    }
}

Kitchen::~Kitchen()
{
  
}
