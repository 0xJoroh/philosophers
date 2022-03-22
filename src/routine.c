#include "../philo.h"

void eat(t_philo *philo)
{
    pthread_mutex_lock(philo->data->eat_mutex);
    philo->last_meal = get_time(); // updat last time he aet
    pthread_mutex_unlock(philo->data->eat_mutex);
    printf("%ld %d is\e[1;32m eating \e[1;37m\n", get_time() - philo->data->simu_start_time, philo->id + 1);
    if (philo->data->nbr_philo_eat >= 0)
        philo->data->nbr_philo_eat--;
    // printf("%d", philo->data->time_to_eat);
    // exit(0);
    pthread_mutex_unlock(philo->data->fork_mutex);
    pthread_mutex_unlock((philo + 1)->data->fork_mutex);
}
void sleeping(t_philo *philo)
{
    usleep(philo->data->time_to_sleep);
    printf("%ld %d is\e[1;33m sleeping \e[1;37m\n", get_time() - philo->data->simu_start_time, philo->id + 1);
}
void think(t_philo *philo)
{
    printf("%ld %d is\033[1;35m thinking \e[1;37m\n", get_time() - philo->data->simu_start_time, philo->id + 1);
}
void take_fork(t_philo *philo)
{
    pthread_mutex_lock(philo->data->fork_mutex);
    printf("%ld %d has\e[1;34m taken a fork \e[1;37m\n", get_time() - philo->data->simu_start_time, philo->id + 1);
    // TODO: get fork of next philo (error in case of end of array)
    printf("%d\n", philo + 1 % philo->data->nbr_philo);
    exit(0);
    pthread_mutex_lock((philo + 1 % philo->data->nbr_philo)->data->fork_mutex);
    printf("%ld %d has\e[1;34m taken a fork \e[1;37m\n", get_time() - philo->data->simu_start_time, philo->id + 1);
}
// [(ph->id + 1) % ph->data->nb_philos]
void *routine(void *arg)
{
    t_philo philo;

    philo = *(t_philo *)arg;
    // pthread_mutex_lock(&philo.data->mutex);
    while (1)
    {
        // check eating limits
        if (philo.data->nbr_philo_eat == 0)
        {
            quit("Number of times each philosopher must eat is reached");
            break; // (stop this thread)
        }
        take_fork(&philo);
        eat(&philo);
        sleeping(&philo);
        think(&philo);
    }
    // pthread_mutex_unlock(&philo.data->mutex);
    return (NULL);
}
