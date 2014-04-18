#ifndef MUTEX_H_
# define MUTEX_H_

#include "exception.h"
#include <pthread.h>

class Mutex
{
 private:
  phread_mutex_t	mutex;
 public:
  Mutex();
  ~Mutex();
  void	lock();
  void	unlock();
  void	trylock();
};

#endif
