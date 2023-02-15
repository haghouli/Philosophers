/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:48:24 by haghouli          #+#    #+#             */
/*   Updated: 2023/02/11 16:47:35 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void    philo_eat(t_philosopher *philo)
{
    sem_wait(philo->data->sem1);
    do_routine("has take a fork",philo);
    sem_wait(philo->data->sem1);
    do_routine("has take a fork",philo);
    do_routine("is eating", philo);
    philo->last_eat = get_current_time_ms();
    usleep(convert_to_usec(philo->data->time_to_eat));
    sem_post(philo->data->sem1);
    sem_post(philo->data->sem1);
}

void    philo_sleep(t_philosopher *philo)
{
    do_routine("is sleeping", philo);
    usleep(convert_to_usec(philo->data->time_to_sleep));
}

void    philo_think(t_philosopher *philo)
{
    do_routine("is sleeping", philo);
}