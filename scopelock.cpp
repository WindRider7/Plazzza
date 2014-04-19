#include "scopelock.h"

ScopeLock::ScopeLock(Mutex &_mutex):mutex(_mutex)
{
  this->mutex.lock();
}

ScopeLock::~ScopeLock()
{
  this->mutex.unlock();
}
