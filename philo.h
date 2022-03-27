/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 04:05:20 by 0x10000           #+#    #+#             */
/*   Updated: 2022/03/27 04:10:16 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct		s_data
{
    int				nbr_philo;
    long			simu_start_time;
    int				time_to_die;
    int				time_to_eat;
    int				time_to_sleep;
    int				nbr_philo_eat;
    pthread_mutex_t	*fork_mutex;
    pthread_mutex_t	*eat_mutex;
    pthread_t		*th;
}					t_data;

typedef struct s_philo
{
    int		id;
    int		eat_nbr;
    long	last_meal;
    t_data	*data;
} t_philo;

void	*routine(void *arg);
int	ft_atoi(const char *str);
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
