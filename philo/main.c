/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:56:10 by haghouli          #+#    #+#             */
/*   Updated: 2023/02/11 18:33:29 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char *av[])
{
	t_data	*data;

	check_errors(ac, av);
	data_init(ac, av, &data);
	mutexs_init(data);
	philo_init(data);
	if (ac == 5)
		philosophers(data);
	if (ac == 6)
		philosophers_2(data);
	mutexs_destroy(data);
	free_all(&data);
	return (0);
}
