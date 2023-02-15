/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:56:10 by haghouli          #+#    #+#             */
/*   Updated: 2023/02/11 16:45:41 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philosophers(t_data *data)
{
	size_t i;

	i = 0;
	while (i < data->ph_number)
	{
		*(data->process[i]) = fork();
		if(*(data->process[i]) == 0)
		{
			if(data->philo[i]->id % 2)
				usleep(1000);
			while (1)
			{
				philo_eat(data->philo[i]);
				philo_sleep(data->philo[i]);
				philo_think(data->philo[i]);
			}
		}
		else
			i++;
	}
	sem_unlink(NAME_1);
	sem_unlink(NAME_2);
	while (wait(NULL) != -1);
}

int	main(int ac, char *av[])
{
	t_data	*data;

	check_errors(ac, av);
	data_init(ac, av, &data);
	philo_init(data);
	if(ac == 5)
		philosophers(data);
	return (0);
}
