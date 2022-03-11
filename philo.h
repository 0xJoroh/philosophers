#ifndef PHILO_H
#define PHILO_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct s_philo
{
    int id;
} t_philo;

typedef struct s_data
{
    int nbr_philo; // number_of_philosophers
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nbr_philo_eat; // number_of_times_each_philosopher_must_eat
} t_data;

int ft_atoi(const char *str);
int checker_and_fill(int argc, char **argv, t_data *data);
int quit(char *msg);

#endif