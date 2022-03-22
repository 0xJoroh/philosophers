#include "../philo.h"

int create_philos(t_data *data, t_philo **philo)
{
    int i;

    i = -1;
    *philo = malloc(data->nbr_philo * sizeof(t_philo));
    if (!*philo)
        return (quit("philo allocation failed"));
    while (++i < data->nbr_philo)
    {
        (*philo)[i].id = i;
        (*philo)[i].eat_nbr = 0;
        (*philo)[i].data = data; // each philo can have access to data, so we can check philo conditions inside routine
    }
    return (0);
}

int simulation(t_data *data, t_philo *philo)
{
    int i;

    i = -1;
    data->th = malloc(data->nbr_philo * sizeof(pthread_t));
    if (!data->th)
        return (quit("data thread malloc failed"));
    pthread_mutex_init(&data->mutex, NULL);

    // create threads
    while (++i < data->nbr_philo)
        if (pthread_create(&data->th[i], NULL, &routine, philo))
            return (quit("Thread failed to create"));

    // wait the threads and return there values
    i = -1;
    while (++i < data->nbr_philo)
        if (pthread_join(data->th[i], NULL))
            return (quit("Thread failed to join"));

    pthread_mutex_destroy(&data->mutex);
    return (0);
}
