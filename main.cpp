#include <iostream>
#include <string>
#include "plazza.h"

int	main(int argc, char **argv)
{
  try
    {
      if (argc != 4)
	throw myException("the number of parameter should be 4");
      Plazza plazza(2, 2, 2);
      plazza.reception(); // Lvl down
    }
  catch(const myException &e)
    {
      std::cerr << e.what() << std::endl;
    }
}
