#include <iostream>
#include <cstdlib> // EXIT_
#include "exception.h"
#include "plazza.h"
#include "parser.h"

void  myExit(int s)
{
  std::cout << " > Exit" << std::endl;
  if (s == 0)
    exit(EXIT_SUCCESS);
  else
    exit(EXIT_FAILURE);
}

int       main(int argc, char const *argv[])
{
  Parser  p;
  params  pr;

try
{
  if (p.start(argc, argv, pr) != 1) // U
    myExit(0);
  Plazza  plazza(pr.m, pr.n, pr.t);

  plazza.reception(); // lvl down
}
catch (const cerrExcept &error)
{
  std::cerr << "Error: " << error.what() << std::endl;
  myExit(1);
}
  myExit(0);
}
