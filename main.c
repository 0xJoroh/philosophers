#include "./philo.h"

void showData(t_philo **philo, int nbr)
{
	printf("nbr_philo\t=\t%d\n", (*philo)[0].data->nbr_philo);
	printf("time_to_die\t=\t%d\n", (*philo)[0].data->time_to_die);
	printf("time_to_eat\t=\t%d\n", (*philo)[0].data->time_to_eat);
	printf("time_to_sleep\t=\t%d\n", (*philo)[0].data->time_to_sleep);
	printf("nbr_philo_eat\t=\t%d\n\n", (*philo)[0].data->nbr_philo_eat);
	printf("data address\t=\t%p\n", (*philo)[i].data);

	for (int i = 0; i < nbr; i++)
	{
		printf("ID:\t\t\t[%d]\n", (*philo)[i].id + 1);
		printf("eat_nbr:\t\t[%d]\n\n", (*philo)[i].eat_nbr);
	}
}

int fonction(int argc, char **argv)
{
	t_data *data;
	t_philo *philo;

	data = NULL;
	philo = NULL;
	if (check_fill(argc, argv, &data))
		return (-1);
	mutex_init(data);
	if (allocate_philos(data, &philo))
		return (-1);
	if (simulation(data, philo))
		return (-1);
	// showData(&philo, ft_atoi(argv[1]));
	mutex_destroy(data);
	__free(philo, data);
	return (0);
}

int main(int argc, char **argv)
{
	fonction(argc, argv);
	// system("leaks philo");
	return 0;
}
