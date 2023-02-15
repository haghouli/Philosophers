/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:07:29 by haghouli          #+#    #+#             */
/*   Updated: 2023/02/03 11:07:35 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

static int	is_space(char c)
{
	if (((c >= 9) && (c <= 13)) || (c == ' '))
		return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	num;
	int				sign;

	num = 0;
	sign = 1;
	while (*str && (is_space(*str) == 1))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ((ft_isdigit(*str) == 1) && *str)
	{
		num = num * 10 + *str - '0';
		if (num > 9223372036854775807 && sign == -1)
			return (0);
		if (num > 9223372036854775807 && sign == 1)
			return (-1);
		str++;
	}
	return ((int)num * sign);
}
