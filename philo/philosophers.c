/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:12:19 by haghouli          #+#    #+#             */
/*   Updated: 2023/02/15 14:27:14 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	dead(t_data *data)
{
	size_t	i;

	while (1)
	{
		i = 0;
		while (i < data->ph_number)
		{
			if (is_dead(data->philo[i]))
			{
				do_routine("died", data->philo[i]);
				data->b = 0;
				detach_all(data);
				break ;
			}
			i++;
		}
		if (data->b == 0)
			break ;
	}
}

void	*routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->id % 2 == 0)
		usleep(100);
	while (philo->data->b)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	philosophers(t_data *data)
{
	size_t i;
	struct timeval t;

	i = 0;
	gettimeofday(&t, NULL);
	data->time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	while (i < data->ph_number)
	{
		if (pthread_create(data->threads[i], NULL, &routine,
				data->philo[i]) != 0)
			perror("Error :");
		i++;
	}
	dead(data);
	i = 0;
	if (data->ph_number != 1 && data->b)
	{
		while (i < data->ph_number)
		{
			if (pthread_join(*(data->threads[i]), NULL) != 0)
				perror("Error :");
			i++;
		}
	}
}