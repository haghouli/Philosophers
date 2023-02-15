/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:51:01 by haghouli          #+#    #+#             */
/*   Updated: 2023/02/15 09:43:17 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	ft_sleep(t_philosopher *philo)
{
	size_t	time;

	time = get_current_time_ms();
	while (philo->data->time_to_sleep > (get_current_time_ms() - time)
		&& philo->data->b)
		usleep(5);
}

void	philo_eat(t_philosopher *philo)
{
	pthread_mutex_lock(philo->data->fork[philo->r_id]);
	do_routine("has take a fork.", philo);
	if (philo->data->b && philo->data->ph_number == 1)
		pthread_detach(*(philo->data->threads[0]));
	pthread_mutex_lock(philo->data->fork[philo->l_id]);
	do_routine("has take a fork.", philo);
	do_routine("is eating.", philo);
	philo->last_eat = get_current_time_ms();
	usleep(convert_to_usec(philo->data->time_to_sleep));
	pthread_mutex_unlock(philo->data->fork[philo->l_id]);
	pthread_mutex_unlock(philo->data->fork[philo->r_id]);
}

void	philo_sleep(t_philosopher *philo)
{
	do_routine("is sleeping", philo);
	usleep(convert_to_usec(philo->data->time_to_sleep));
}

void	detach_all(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->ph_number)
		pthread_detach(*(data->threads[i++]));
}

void	philo_think(t_philosopher *philo)
{
	do_routine("is thinking", philo);
}

int	is_dead(t_philosopher *philo)
{
	if (philo->data->time_to_die < get_diff(philo->last_eat))
		return (1);
	return (0);
}
