/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 05:13:40 by haghouli          #+#    #+#             */
/*   Updated: 2023/02/11 11:28:08 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	data_init(int ac, char **av, t_data **data)
{
	size_t	i;

	i = 0;
	(*data) = malloc(sizeof(t_data));
	(*data)->ph_number = ft_atoi(av[1]);
	(*data)->time_to_die = ft_atoi(av[2]);
	(*data)->time_to_eat = ft_atoi(av[3]);
	(*data)->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		(*data)->nbr_time_to_eat = ft_atoi(av[5]);
	(*data)->threads = malloc(sizeof(pthread_t *) * (*data)->ph_number);
	while (i < (*data)->ph_number)
		(*data)->threads[i++] = malloc(sizeof(pthread_t));
	(*data)->b = 1;
	(*data)->fork = malloc(sizeof(pthread_mutex_t *) * (*data)->ph_number);
	i = 0;
	while (i < (*data)->ph_number)
		(*data)->fork[i++] = malloc(sizeof(pthread_mutex_t));
	(*data)->philo = malloc(sizeof(t_philosopher *) * (*data)->ph_number);
	i = 0;
	while (i < (*data)->ph_number)
		(*data)->philo[i++] = malloc(sizeof(t_philosopher));
}

void	mutexs_init(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->ph_number)
		pthread_mutex_init(data->fork[i++], NULL);
	pthread_mutex_init(&data->mute, NULL);
	pthread_mutex_init(&data->check, NULL);
}

void	philo_init(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->ph_number)
	{
		data->philo[i]->id = i + 1;
		if (i == data->ph_number - 1)
		{
			data->philo[i]->r_id = i;
			data->philo[i]->l_id = 0;
		}
		else
		{
			data->philo[i]->r_id = i;
			data->philo[i]->l_id = i + 1;
		}
		data->philo[i]->data = data;
		data->philo[i]->last_eat = get_current_time_ms();
		data->philo[i]->time_eat = 0;
		i++;
	}
}

void	mutexs_destroy(t_data *data)
{
	size_t i;

	i = 0;
	while (i < data->ph_number)
		pthread_mutex_destroy(data->fork[i++]);
}