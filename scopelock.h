#ifndef ScopeLock_H_
# define ScopeLock_H_

#include "mutex.h"

class ScopeLock
{
 private:
  Mutex mutex;
 public:
  ScopeLock(Mutex&);
  ~ScopeLock();
};

#endif
