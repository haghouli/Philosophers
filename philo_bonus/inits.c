/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:42:00 by haghouli          #+#    #+#             */
/*   Updated: 2023/02/11 16:47:20 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	(*data)->process = malloc(sizeof(pid_t *) * (*data)->ph_number);
	while (i < (*data)->ph_number)
		(*data)->process[i++] = malloc(sizeof(pid_t));
	(*data)->philo = malloc(sizeof(t_philosopher *) * (*data)->ph_number);
	i = 0;
	while (i < (*data)->ph_number)
		(*data)->philo[i++] = malloc(sizeof(t_philosopher));
	(*data)->sem1 = sem_open(NAME_1, O_CREAT | S_IRUSR | S_IWUSR, 0777, (*data)->ph_number);
	//(*data)->sem2 = sem_open(NAME_2, O_CREAT | S_IRUSR | S_IWUSR, 0777, (*data)->ph_number / 2);
	gettimeofday(&(*data)->time, NULL);
	(*data)->b = 1;
}

void	philo_init(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->ph_number)
	{
		data->philo[i]->id = i + 1;
		data->philo[i]->data = data;
		data->philo[i]->last_eat = get_current_time_ms();
		data->philo[i]->time_eat = 0;
		i++;
	}
}