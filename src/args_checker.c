#include "../philo.h"

static void fill_data(t_data *data, int i, int value)
{
    if (i == 1)
        data->nbr_philo = value;
    else if (i == 2)
        data->time_to_die = value;
    else if (i == 3)
        data->time_to_eat = value;
    else if (i == 4)
        data->time_to_sleep = value;
    else if (i == 5)
        data->nbr_philo_eat = value;
}

int checker_and_fill(int argc, char **argv, t_data *data)
{
    int i;

    if (argc != 5 && argc != 6)
        return quit("Arguments must be between 4 to 5");
    i = 0;
    while (++i < argc)
        if (ft_atoi(argv[i]) >= 0)
            fill_data(data, i, ft_atoi(argv[i]));
        else
            return quit("Arguments must be numbers ");
    if (!data->nbr_philo)
        return quit(NULL);
    return (0);
}