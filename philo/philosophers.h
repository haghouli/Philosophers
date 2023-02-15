/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:55:50 by haghouli          #+#    #+#             */
/*   Updated: 2023/02/11 18:28:10 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	size_t					ph_number;
	size_t					time_to_die;
	size_t					time_to_eat;
	size_t					time_to_sleep;
	size_t					nbr_time_to_eat;
	pthread_t				**threads;
	int						b;
	pthread_mutex_t			mute;
	size_t					time;
	pthread_mutex_t			**fork;
	struct s_philosopher	**philo;
	pthread_mutex_t			check;
}							t_data;

typedef struct s_philosopher
{
	size_t					id;
	size_t					r_id;
	size_t					l_id;
	size_t					last_eat;
	size_t					time_eat;
	t_data					*data;
}							t_philosopher;

/********************************* utiles ********************************/
int							ft_atoi(const char *str);
int							ft_isdigit(char c);
void						check_errors(int ac, char **av);
size_t						convert_to_usec(size_t time);
size_t						get_current_time_ms(void);
size_t						get_current_time_us(void);
void						do_routine(char *str, t_philosopher *philo);

/******************************** inits ***********************************/
void						data_init(int ac, char **av, t_data **data);
void						mutexs_init(t_data *data);
void						philo_init(t_data *data);
void						mutexs_destroy(t_data *data);
size_t						get_diff(size_t last_eat);

/******************************** routines ***********************************/
void						philo_eat(t_philosopher *philo);
void						philo_sleep(t_philosopher *philo);
void						philo_think(t_philosopher *philo);
int							is_dead(t_philosopher *philo);

/******************************** others ***********************************/
void						philosophers(t_data *data);
void						philosophers_2(t_data *data);
void						free_all(t_data **data);
void						detach_all(t_data *data);

#endif