#ifndef PHILO_H
#define PHILO_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
typedef struct s_data
{
    int nbr_philo; // number_of_philosophers
    long simu_start_time;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nbr_philo_eat; // number_of_times_each_philosopher_must_eat
    pthread_mutex_t *fork_mutex;
    pthread_mutex_t *eat_mutex;
    pthread_t *th;
} t_data;

typedef struct s_philo
{
    int id;
    int eat_nbr; // number_of_times_each_philosopher_must_eat
    long last_meal;
    int is_eating;
    t_data *data;
} t_philo;

void *routine(void *arg);
int ft_atoi(const char *str);
int check_fill(int argc, char **argv, t_data **data);
int simulation(t_data *data, t_philo *philo);
int allocate_philos(t_data *data, t_philo **philo);
void __free(t_philo *philo, t_data *data);
void mutex_init(t_data *data);
void mutex_destroy(t_data *data);
int quit(char *msg);
long get_time(void);
void status(t_philo *philo, int state);
void u_sleep(unsigned long usec);

#endif
