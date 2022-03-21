#include "./philo.h"

void showData(t_data data, t_philo **philo, int nbr)
{
	printf("nbr_philo\t=\t%d\n", data.nbr_philo);
	printf("time_to_die\t=\t%d\n", data.time_to_die);
	printf("time_to_eat\t=\t%d\n", data.time_to_eat);
	printf("time_to_sleep\t=\t%d\n", data.time_to_sleep);
	printf("nbr_philo_eat\t=\t%d\n", data.nbr_philo_eat);

	for (int i = 0; i < nbr; i++)
		printf("\nID:\t\t\t[%d]\n", (*philo)[i].id);
}

static void create_philos(int nbr, t_philo **philo)
{
	int i;

	i = -1;
	*philo = (t_philo *)malloc(nbr * sizeof(t_philo *));
	if (!*philo)
		quit("philo allocation failed");
	while (++i < nbr)
		(*philo)[i].id = i;
}

int fonction(int argc, char **argv)
{
	t_data data;
	t_philo *philo;

	philo = NULL;
	if (checker_and_fill(argc, argv, &data))
		return (-1);
	create_philos(data.nbr_philo, &philo);

	// showData(data, &philo, ft_atoi(argv[1]));

	// pthread_t thread_id, thread_id2;
	// pthread_mutex_t mutex;

	// pthread_mutex_init(&mutex, NULL);

	// pthread_create(&thread_id, NULL, &routine, &mutex);
	// pthread_create(&thread_id2, NULL, &routine, &mutex);
	// pthread_join(thread_id, NULL);
	// pthread_join(thread_id2, NULL);

	// pthread_mutex_destroy(&mutex);

	// printf("counter: %d\n", counter);

	free(philo);
	return (0);
}

int main(int argc, char **argv)
{
	fonction(argc, argv);
	// system("leaks philo");
	return 0;
}

// pthread_create
// pthread_mutex_init
// pthread_mutex_lock
// pthread_mutex_unlock
// gettimeofday
// usleep

// pthread_join (optional)