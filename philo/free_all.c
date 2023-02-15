/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:04:46 by haghouli          #+#    #+#             */
/*   Updated: 2023/02/11 11:37:10 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	free_all(t_data **data)
{
	size_t i;

	i = 0;
	while (i < (*data)->ph_number)
	{
		free((*data)->threads[i]);
		free((*data)->fork[i]);
		free((*data)->philo[i]);
		i++;
	}
	free((*data)->threads);
	free((*data)->fork);
	free((*data)->philo);
}