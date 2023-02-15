/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:12:54 by haghouli          #+#    #+#             */
/*   Updated: 2023/02/07 11:01:07 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

size_t	convert_to_usec(size_t time)
{
	return (time * 1000);
}

size_t	get_current_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

size_t	get_current_time_us(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000000) + time.tv_usec);
}

void	do_routine(char *str, t_philosopher *philo)
{
	if (philo->data->b)
		printf("%zums %zu %s\n", get_current_time_ms()
				- ((philo->data->time.tv_sec * 1000)
					+ (philo->data->time.tv_usec / 1000)), philo->id, str);
}

size_t	get_diff(size_t last_eat)
{
	return (get_current_time_ms() - last_eat);
}