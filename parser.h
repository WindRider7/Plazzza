#ifndef _PARSER_H_
# define _PARSER_H_

#include <string>

struct params
{
  int m;
  int n;
  int t;
};

class         Parser
{
private:
  std::string helpArg_;

  bool        isDigits(const std::string &str) const;
  int         str2int(const std::string &str) const;
  params      parse(std::string M, std::string N, std::string T);

public:
  Parser();
  ~Parser();

  int         start(int argc, char const *argv[], params &pr);
};

#endif // !_PARSER_H_
