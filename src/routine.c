#include "../philo.h"

void *routine(pthread_mutex_t *mutex)
{
    pthread_mutex_lock(mutex);
    // routine
    pthread_mutex_unlock(mutex);
    return NULL;
}