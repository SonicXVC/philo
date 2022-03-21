/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:49:04 by ameteori          #+#    #+#             */
/*   Updated: 2022/03/18 19:04:01 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex()
{
	
}

int init_philo(t_gamerules *rules)
{
	int	i;

	i = rules->nb_of_philos;
	while (--i >= 0)
	{
		rules->philos[i].id = i;
		rules->philos[i].left = i;
		rules->philos[i].right = (i + 1) % rules->nb_of_philos;
		rules->philos[i].last_eat = 0;
		rules->philos[i].rules = rules;
	}
}

int	general_init(t_gamerules *rules, char **av)
{
	rules->nb_of_philos = ft_atoi(av[1]);
	rules->time_to_die = ft_atoi(av[2]);
	rules->time_to_eat = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	rules->died = 0;
	rules->all_ate = 0;
	if (rules->nb_of_philos < 2 || rules->time_to_die < 0 || rules->time_to_eat < 0
		|| rules->time_to_sleep < 0 || rules->nb_of_philos > MAX_THREADS)
		return (1);
	if (av[5])
	{
		rules->must_eat = ft_atoi(av[5]);
		if (rules->must_eat <= 0)
			return (1);
	}
	else
		rules->must_eat = -1;
	if (init_mutex())
		return (2);
	init_philo(rules);
}