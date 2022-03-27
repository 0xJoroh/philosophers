/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 03:46:37 by mait-si-          #+#    #+#             */
/*   Updated: 2022/03/27 04:04:55 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	fill_data(t_data *data, int i, int value)
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

int	check_fill(int argc, char **argv, t_data **data)
{
	int	i;

	i = 0;
	if (argc != 5 && argc != 6)
		return (quit("Arguments must be between 4 to 5"));
	if (ft_atoi(argv[1]) <= 0)
		return (quit(NULL));
	*data = malloc(sizeof(t_data));
	if (!*data)
		return (quit("data malloc failed"));
	if (argc == 5)
		(*data)->nbr_philo_eat = -1;
	while (++i < argc)
	{
		if (ft_atoi(argv[i]) >= 0)
			fill_data(*data, i, ft_atoi(argv[i]));
		else
			return (quit("Arguments must be numbers"));
	}
	if (!(*data)->nbr_philo_eat)
		return (quit(NULL));
	return (0);
}
