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
        (*philo)[i].data = data; // each philo can have access to data, so we can check philo conditions inside routine
    }
    return (0);
}

int is_dead(t_philo *philo)
{
    int i;
    int d;

    while (1)
    {
        d = 0;
        i = -1;
        while (++i < philo->data->nbr_philo)
            if (philo[i].eat_nbr == 0)
                d++;
        if (d == philo->data->nbr_philo)
            return (1);

        i = -1;
        while (++i < philo->data->nbr_philo)
            if ((get_time() - philo[i].last_meal) >= (philo[i].data->time_to_die * 1000))
            {
                status(&philo[i], 6);
                return (1);
            }
        // usleep(100);
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
        philo[i].last_meal = get_time();
        // create threads each 100 microseconds
        if (pthread_create(&data->th[i], NULL, &routine, &philo[i]))
            return (quit("Thread failed to create"));
        usleep(100);
    }
    // check death (time_to_die)

    // wait the threads and return there values
    if (is_dead(philo))
        return (1); // (stop the simulation)
    // i = -1;
    // while (++i < data->nbr_philo)
    //     if (pthread_join(data->th[i], NULL))
    //         return (quit("Thread failed to join"));
    return (0);
}
