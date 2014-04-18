#include "Mutex.h"

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
    throw myException("MUTEX LOCK");
}

void	Mutex::unlock()
{
  if (pthread_mutex_unlock(&this->mutex))
    throw myException("MUTEX UNLOCK");
}

void	Mutex::trylock()
{
  if (pthread_mutex_trylock(&this->mutex))
    throw myException("MUTEX TRYLOCK");
}
