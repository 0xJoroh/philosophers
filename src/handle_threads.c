#include "../philo.h"

int allocate_philos(t_data *data, t_philo **philo)
{
    int i;

    i = -1;
    *philo = malloc(data->nbr_philo * sizeof(t_philo));
    if (!*philo)
        return (quit("philo allocation failed"));

    while (++i < data->nbr_philo)
    {
        (*philo)[i].id = i;
        (*philo)[i].eat_nbr = data->nbr_philo_eat;
        (*philo)[i].last_meal = 0;
        (*philo)[i].data = data; // each philo can have access to data, so we can check philo conditions inside routine
    }
    return (0);
}

int simulation(t_data *data, t_philo *philo)
{
    int i;

    i = -1;
    // allocate threads with number of philos
    data->th = malloc(data->nbr_philo * sizeof(pthread_t));
    if (!data->th)
        return (quit("data thread malloc failed"));
    // start simulation
    data->simu_start_time = get_time();
    while (++i < data->nbr_philo)
    {
        // create threads
        if (pthread_create(&data->th[i], NULL, &routine, &philo[i]))
            return (quit("Thread failed to create"));
        usleep(100);
    }
    // check death (time_to_die)
    // if (is_dead(&philo))
    //     break; // (stop the simulation)

    // wait the threads and return there values
    i = -1;
    while (++i < data->nbr_philo)
        if (pthread_join(data->th[i], NULL))
            return (quit("Thread failed to join"));
    return (0);
}
