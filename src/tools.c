#include "../philo.h"

int quit(char *msg)
{
    if (msg)
        printf("%s\n", msg);
    return (1);
}

void __free(t_philo *philo, t_data *data)
{
    if (philo)
        free(philo);
    if (data->th)
        free(data->th);
    if (data)
        free(data);
}

long get_time(void)
{
    struct timeval current_time;

    gettimeofday(&current_time, NULL);
    return ((current_time.tv_usec + current_time.tv_sec * 1000000));
}

void mutex_init(t_data *data)
{
    int i;

    i = -1;
    data->fork_mutex = malloc(sizeof(pthread_mutex_t) * data->nbr_philo);
    data->eat_mutex = malloc(sizeof(pthread_mutex_t) * data->nbr_philo);
    while (++i <= data->nbr_philo)
    {
        pthread_mutex_init(&data->fork_mutex[i], NULL);
        pthread_mutex_init(&data->eat_mutex[i], NULL);
    }
}