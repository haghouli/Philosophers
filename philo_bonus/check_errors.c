/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 08:12:05 by haghouli          #+#    #+#             */
/*   Updated: 2023/02/03 11:28:16 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		return (0);
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_errors(int ac, char **av)
{
	int	i;
	int	nbr;

	i = 0;
	if (ac != 6 && ac != 5)
	{
		printf("Too Many argument.\n");
		exit(1);
	}
	if (ac == 6)
		nbr = 6;
	if (ac == 5)
		nbr = 5;
	i = 1;
	while (i < nbr)
	{
		if (ft_atoi(av[i]) < 0 || !is_number(av[i]))
			exit(1);
		i++;
	}
}
