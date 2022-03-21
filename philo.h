/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:49:07 by ameteori          #+#    #+#             */
/*   Updated: 2022/03/18 18:43:41 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdbool.h>

# define MAX_THREADS 200

typedef struct s_philo
{
	int				id;
	unsigned int 	left;
	unsigned int 	right;
	int				count_of_eats;
	int				last_eat;
	struct t_gamerules	*rules;
	pthread_t		thread_id;
	
}				t_philo;

typedef struct s_gamerules
{
	int				nb_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				died;
	int				all_ate;
	t_philo			philos[MAX_THREADS];
	pthread_mutex_t forks[MAX_THREADS];
	pthread_mutex_t for_print;
	
}				t_gamerules;

#endif