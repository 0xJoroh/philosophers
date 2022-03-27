/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 03:57:59 by 0x10000           #+#    #+#             */
/*   Updated: 2022/03/27 03:58:46 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	mutex_init(t_data *data)
{
	int	i;

	i = -1;
	data->fork_mutex = malloc(sizeof(pthread_mutex_t) * data->nbr_philo);
	data->eat_mutex = malloc(sizeof(pthread_mutex_t) * data->nbr_philo);
	while (++i < data->nbr_philo)
	{
		pthread_mutex_init(&data->fork_mutex[i], NULL);
		pthread_mutex_init(&data->eat_mutex[i], NULL);
	}
}

void	mutex_destroy(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
	{
		pthread_mutex_destroy(&data->fork_mutex[i]);
		pthread_mutex_destroy(&data->eat_mutex[i]);
	}
}
