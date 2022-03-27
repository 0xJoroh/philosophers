/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 03:46:37 by mait-si-          #+#    #+#             */
/*   Updated: 2022/03/27 03:52:26 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	fonction(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	data = NULL;
	philo = NULL;
	if (check_fill(argc, argv, &data))
		return (-1);
	mutex_init(data);
	if (allocate_philos(data, &philo))
		return (-1);
	if (simulation(data, philo))
		return (-1);
	mutex_destroy(data);
	__free(philo, data);
	return (0);
}

int	main(int argc, char **argv)
{
	fonction(argc, argv);
	return (0);
}
