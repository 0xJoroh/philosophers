#include "../philo.h"

void eat()
{
    printf("\e[1;32mEating \e[1;37m\n");
}
void sleeping()
{
    printf("\e[1;33mSleeping \e[1;37m\n");
}
void think()
{
    printf("\033[1;35mThinking \e[1;37m\n");
}
void take_fork()
{
    printf("\e[1;34mTakeing fork \e[1;37m\n");
}

void *routine(void *arg)
{
    t_philo philo;

    // pthread_mutex_lock(mutex);
    philo = *(t_philo *)arg;
    // for (int i = 0; i <)
    // {
    // }
    // printf("%d \n", philo.id);
    // take_fork();
    // eat();
    // sleeping();
    // think();
    // pthread_mutex_unlock(mutex);
    return (NULL);
}
