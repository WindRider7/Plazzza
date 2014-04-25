#include "parser.h"

#include <iostream>
#include <sstream>
#include "exception.h"

Parser::Parser() 
{
  helpArg_ = "--help";
}

Parser::~Parser() {}

bool  Parser::isDigits(const std::string &str) const
{
  return str.find_first_not_of("0123456789") == std::string::npos;
}

int                 Parser::str2int(const std::string &str) const
{
  std::stringstream ss(str);
  int               num;

  if ((ss >> num).fail())
    throw cerrExcept("'str2int' error");
  return num;
}

params    Parser::parse(std::string M, std::string N, std::string T)
{
  params  tmp;

  if (!isDigits(M) || !isDigits(N) || !isDigits(T))
    throw coutExcept(" > Invalid value passed");
  tmp.m = str2int(M);
  tmp.n = str2int(N);
  tmp.t = str2int(T);
  return tmp;
}

int   Parser::start(int argc, char const *argv[], params &pr)
{

try
{
  if (argc > 1)
  {
    if (helpArg_.compare(argv[1]) == 0)
    {
      std::cout << " > Usage: './plazza M N T'" << std::endl
                << "Where : " << std::endl
                << "M - multiplier for the cooking time" << std::endl
                << "N - number of cooks per kitchen" << std::endl
                << "T - stock time to replace ingredients (ms)" << std::endl;
      return -1;
    }
  }
  if (argc != 4)
    throw coutExcept(" > Invalid number of arguments");
  pr = parse(argv[1], argv[2], argv[3]); // ->
}
catch (const coutExcept &error)
{
  std::cout << error.what() << std::endl
            << "Use: './plazza --help' for info" << std::endl;
  return -1;
}
  return 1;
}
