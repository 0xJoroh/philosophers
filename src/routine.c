/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 04:02:52 by 0x10000           #+#    #+#             */
/*   Updated: 2022/03/27 04:03:49 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork_mutex[philo->id]);
	status(philo, 1);
	pthread_mutex_lock(&philo->data->fork_mutex[(philo->id + 1) % \
	philo->data->nbr_philo]);
	status(philo, 1);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->eat_mutex[philo->id]);
	philo->last_meal = get_time();
	status(philo, 2);
	pthread_mutex_unlock(&philo->data->eat_mutex[philo->id]);
	u_sleep(philo->data->time_to_eat * 1000);
	philo->eat_nbr--;
	pthread_mutex_unlock(&philo->data->fork_mutex[(philo->id + 1) % \
	philo->data->nbr_philo]);
	pthread_mutex_unlock(&philo->data->fork_mutex[philo->id]);
}

void	sleeping(t_philo *philo)
{
	status(philo, 3);
	u_sleep(philo->data->time_to_sleep * 1000);
}

void	think(t_philo *philo)
{
	status(philo, 4);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->eat_nbr == 0)
			return (NULL);
		take_fork(philo);
		eat(philo);
		sleeping(philo);
		think(philo);
	}
	return (NULL);
}
