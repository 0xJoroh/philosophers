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