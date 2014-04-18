#include "parse.h"
#include <iostream>
#include <sstream>

Parse::Parse()
{
  this->types["regina"] = "1";
  this->types["margarita"] = "2";
  this->types["americaine"] = "4";
  this->types["fantasia"] = "8";
  this->sizes["S"] = "01";
  this->sizes["M"] = "02";
  this->sizes["L"] = "04";
  this->sizes["XL"] = "08";
  this->sizes["XXL"] = "16";
  this->pizza_count = 0;
}

static	int	check_num(std::string &num)
{
  if (num.size() < 2 || num.size() > 4)
    return (1);
  if (num.at(0) != 'x')
    return (1);
  else if (num.at(1) < '1' || num.at(1) > '9')
    return (1);
  if (num.size() == 3)
    if (num.at(2) < '0' || num.at(2) > '9')
      return (1);
  return (0);
}

int	Parse::pack_data(std::string &type, std::string &size, std::string &num)
{
  std::ostringstream	os;
  int		n;
  int		i;
  
  i = 0;
  if (check_num(num) == 1)
    return (1);
  if (this->types.find(type) == this->types.end())
    return (1);
  if (this->sizes.find(size) == this->sizes.end())
    return (1);
  os << this->types[type] << this->sizes[size];
  std::istringstream	is(num.substr(1, num.size() - 1));
  is >> n;
  while (i < n)
    {
      std::string  *pizza = new std::string();
      pizza->assign(os.str());
      this->order.push_back(pizza);
      i = i + 1;
    }
  std::cout << "this->order.size" << this->order.size() << std::endl;
  this->pizza_count = this->pizza_count + n;
  return (0);
}

int	Parse::get_order(int p, int tmp, std::string &msg)
{
  std::string	cmd;
  std::string	type;
  std::string	size;
  std::string	num;

  if (tmp != 0)
    tmp = tmp + 1;
  cmd = msg.substr(tmp, p);
  std::istringstream	is(cmd);
  is >> type >> size >> num;
  if (type.empty() || size.empty() || num.empty())
    return (1);
  return (pack_data(type, size, num));
}

void	Parse::getinfo(std::string &msg)
{
  int	p;
  int	i;
  int	tmp;

  i = 0;
  p = 0;
  tmp = 0;
  while ((p = msg.find(';', p + 1)) != -1)
    {
      if (this->get_order(p, tmp, msg))
	std::cout << "order error" << std::endl;
      tmp = p;
      i = i + 1;
    }
  if (i == 0)
    throw myException("Order error: no ';' as an end");
}

int	Parse::get_count()
{
  return this->pizza_count;
}

std::string*	Parse::get_order_one_pizza()
{
  return (*(this->order.begin()));
}

void	Parse::order_pop()
{
  this->pizza_count = this->pizza_count - 1;
  this->order.pop_front();
  std::cout << this->order.size() << std::endl;
}

Parse::~Parse()
{

}
