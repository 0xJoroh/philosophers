/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 03:46:37 by mait-si-          #+#    #+#             */
/*   Updated: 2022/03/27 04:02:06 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	allocate_philos(t_data *data, t_philo **philo)
{
	int	i;

	i = -1;
	*philo = malloc(data->nbr_philo * sizeof(t_philo));
	if (!*philo)
		return (quit("philo allocation failed"));
	while (++i < data->nbr_philo)
	{
		(*philo)[i].id = i;
		(*philo)[i].eat_nbr = data->nbr_philo_eat;
		(*philo)[i].data = data;
	}
	return (0);
}

int	is_dead(t_philo *philo)
{
	int	i;
	int	d;

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
		{
			if ((get_time() - philo[i].last_meal) >= \
			(philo[i].data->time_to_die * 1000))
			{
				status(&philo[i], 6);
				return (1);
			}
		}
	}
	return (0);
}

int	simulation(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	data->th = malloc(data->nbr_philo * sizeof(pthread_t));
	if (!data->th)
		return (quit("data thread malloc failed"));
	data->simu_start_time = get_time();
	while (++i < data->nbr_philo)
	{
		philo[i].last_meal = get_time();
		if (pthread_create(&data->th[i], NULL, &routine, &philo[i]))
			return (quit("Thread failed to create"));
		usleep(100);
	}
	if (is_dead(philo))
		return (1);
	return (0);
}
