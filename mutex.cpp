#include "mutex.h"

Mutex::Mutex()
{
  pthread_mutex_init(&this->mutex, NULL);
}

Mutex::~Mutex()
{
  pthread_mutex_destroy(&this->mutex);
}

void	Mutex::lock()
{
  if (pthread_mutex_lock(&this->mutex))
    throw cerrExcept("MUTEX LOCK");
}

void	Mutex::unlock()
{
  if (pthread_mutex_unlock(&this->mutex))
    throw cerrExcept("MUTEX UNLOCK");
}

void	Mutex::trylock()
{
  //  if (pthread_mutex_trylock(&this->mutex))
  //  throw cerrExcept("MUTEX TRYLOCK");
}
