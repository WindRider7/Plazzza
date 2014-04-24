#include "plazza.h"
#include <stdio.h>

Plazza::Plazza(int _multiplier, int _cooks, int _time)
{
  this->multiplier = _multiplier;
  this->cooks = _cooks;
  this->time = _time;
  this->num = 0;
  this->pid = getpid();
}

void	Plazza::assign_to_kitchen(std::string *pizza)
{
  std::list<Fifo*>::iterator	itin;
  std::list<Fifo*>::iterator	itout;
  std::string res;
  int	_pid;

  itin = this->fifosin.begin();
  itout = this->fifosout.begin();
  std::cout << "pizza string ->" << *pizza << "<-" << std::endl;
  while (itin != this->fifosin.end())
    {
      std::cout << "1111111111111" << std::endl;
      *(*itout) << *pizza;
      *(*itin) >> res;
      std::cout << "222222222222222" << std::endl;
      if (res.compare(0, 4, "succ") == 0)
	break ;
      itin++;
      itout++;
    }
  this->num = this->num + 1;
  Fifo	*fifoin = new Fifo(this->num, 0);
  Fifo	*fifoout = new Fifo(this->num, 1);

  this->fifosin.push_back(fifoin);
  this->fifosout.push_back(fifoout);
  std::cout << "forking ..." << std::endl;
  if ((_pid = fork()) < 0) // check if fork fails
    {
      std::cout << "fork error" << std::endl;
      return ;
    }
  if (_pid == 0)
    {
      Kitchen	kitchen(this->multiplier, this->cooks, this->time);
      kitchen.work(fifoout, fifoin);
      std::cout << "end work" << std::endl;
    }
  else
    {
      std::cout << "small else" << std::endl;
    }
}


void	        Plazza::reception()
{
  std::string msg;
  Parse       parse; // types + sizes init
/*p.s i moved parse here since the order_pop() setting counter back to 
  0 and deleting pizzas, when all orders procced, meaning you don't need 
  to recreate the instanse 'Parse' to call the 'getinfo' function
  Am I right? :) */
  if (this->pid = getpid())
    {
      while (1)
	{ 
    std::cout << "Enter the commands :" << std::endl;
	  getline(std::cin, msg);
	  if (msg.compare(0, 4, "quit") == 0)
    {
	    return ;
    }
	  parse.getinfo(msg); // U
	  while (parse.get_count())
	    {
	      assign_to_kitchen(parse.get_order_one_pizza()); // lvl down (U)
	      parse.order_pop();
	    }
	}
    }
    else
      std::cout << "TEST" << std::endl;
    // Lvl up
}

Plazza::~Plazza()
{

}
