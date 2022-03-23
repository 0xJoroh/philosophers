#include "../philo.h"

void take_fork(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->fork_mutex[philo->id]); // lock the fork mutex of current philo
    status(philo, 1);
    // Get fork of next philo (id + 1 % nbr_philo) in case of end of array
    pthread_mutex_lock(&philo->data->fork_mutex[(philo->id + 1) % philo->data->nbr_philo]); // lock the fork mutex of next philo
    status(philo, 1);
}

void eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->eat_mutex[philo->id]);
    philo->last_meal = get_time(); // Updat last time he aet
    pthread_mutex_unlock(&philo->data->eat_mutex[philo->id]);
    status(philo, 2);
    // Decrement number of times each philosopher must eat
    u_sleep(philo->data->time_to_eat * 1000);
    philo->eat_nbr--;
    // Unlock both forks for next philos
    pthread_mutex_unlock(&philo->data->fork_mutex[(philo->id + 1) % philo->data->nbr_philo]);
    pthread_mutex_unlock(&philo->data->fork_mutex[philo->id]);
}

void sleeping(t_philo *philo)
{
    status(philo, 3);
    u_sleep(philo->data->time_to_sleep * 1000);
}

void think(t_philo *philo)
{
    status(philo, 4);
}

void *routine(void *arg)
{
    t_philo philo;

    philo = *(t_philo *)arg;
    while (1)
    {
        // check eating limits
        if (philo.eat_nbr == 0)
        {
            // status(&philo, 5);
            return (NULL); // (stop this thread)
        }
        take_fork(&philo);
        eat(&philo);
        sleeping(&philo);
        think(&philo);
    }
    return (NULL);
}
