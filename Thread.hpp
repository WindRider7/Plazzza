#ifndef THREAD_H_
# define THREAD_H_

#include <pthread.h>

class Thread
{
private:
  char	status;
  pthread_t	thread;
public:
  Thread()
  {
    this->status = 0;
  }
  
  void	start(void* (*fun)(void *), void *para)
  {
    this->status = 1;
    if (pthread_create(&this->thread, NULL, fun, para))
      {
	std::cout << "phread creat fail" << std::endl;
	return ;
      }
  }
  
  void	wait()
  {
    this->status = 2;
    if (pthread_join(thread, NULL))
      return ;
  }
    
  ~Thread()
  {
    
  }
};

#endif
