/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 06:43:32 by haghouli          #+#    #+#             */
/*   Updated: 2023/02/11 18:34:35 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	dead_2(t_data *data)
{
	size_t	i;

	usleep(convert_to_usec(data->time_to_eat));
	while (1)
	{
		i = 0;
		while (i < data->ph_number)
		{
			if (is_dead(data->philo[i])
				&& data->philo[i]->time_eat != data->nbr_time_to_eat)
			{
				do_routine("died", data->philo[i]);
				detach_all(data);
				data->b = 0;
				break ;
			}
			break ;
			i++;
		}
		if (data->b == 0 || data->philo[i]->time_eat == data->nbr_time_to_eat)
			break ;
	}
}

void	*routine_2(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->id % 2 == 0)
		usleep(100);
	while (philo->data->b && philo->time_eat < philo->data->nbr_time_to_eat)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		philo->time_eat++;
	}
	return (NULL);
}

void	philosophers_2(t_data *data)
{
	size_t			i;
	struct timeval	t;

	i = 0;
	gettimeofday(&t, NULL);
	data->time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	while (i < data->ph_number)
	{
		if (pthread_create(data->threads[i], NULL, &routine_2,
				data->philo[i]) != 0)
			perror("Error :");
		i++;
	}
	dead_2(data);
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
