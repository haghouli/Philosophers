#include "philosophers.h"

int	main(void)
{
	pthread_mutex_t **t;

	t = malloc(sizeof(pthread_mutex_t *) * 10);

	for (int i = 0; i < 10; i++)
	{
		pthread_mutex_init(t[i], NULL);
		i++;
	}

	for (int i = 0; i < 10; i++)
	{
		free(t[i]);
		i++;
	}
}