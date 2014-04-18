#ifndef PARSE_H_
# define PARSE_H_

#include "exception.h"
#include <list>
#include <map>
#include <string>
#include <sstream>

class Parse
{
 private:
  std::list<std::string*>	order;
  std::map<std::string, std::string>	types;
  std::map<std::string, std::string>	sizes;
  int			       pizza_count;
 public:
  Parse();
  ~Parse();
  void	getinfo(std::string &msg);
  int  pack_data(std::string &type, std::string &size, std::string &num);
  int  get_order(int p, int tmp, std::string &msg);
  int	get_count();
  std::string	*get_order_one_pizza();
  void  order_pop();
};

#endif
