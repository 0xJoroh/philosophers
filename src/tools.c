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

void status(t_philo *philo, int state)
{
    long time = (get_time() - philo->data->simu_start_time) / 1000;
    if (state == 1)
        printf("\e[1;34m%ld %d has taken a fork \e[1;37m\n", time, philo->id + 1);
    else if (state == 2)
        printf("\e[1;32m%ld %d is eating \e[1;37m\n", time, philo->id + 1);
    else if (state == 3)
        printf("\e[1;33m%ld %d is sleeping \e[1;37m\n", time, philo->id + 1);
    else if (state == 4)
        printf("\033[1;35m%ld %d is thinking \e[1;37m\n", time, philo->id + 1);
    else if (state == 5)
        printf("Philo %d is reached times must eat\n", philo->id + 1);
    else if (state == 6)
        printf("\e[1;31m%ld %d died\e[1;37m\n", time, philo->id + 1);
}

void u_sleep(unsigned long usec)
{
    unsigned long start_time;

    start_time = get_time();
    usleep(usec - 1000);
    while (((get_time() - start_time) * 1000) < usec)
        ;
}
