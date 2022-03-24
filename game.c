/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:15:36 by ameteori          #+#    #+#             */
/*   Updated: 2022/03/24 19:25:27 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eating(t_philo *philo)
{
	t_gamerules	*rules;

	rules = philo->rules;
	pthread_mutex_lock(&(rules->forks[philo->left]));
	print_action(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->forks[philo->right]));
	print_action(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->meal_check));
	print_action(rules, philo->id, "is eating");
	philo->last_eat = timestamp();
	pthread_mutex_unlock(&(rules->meal_check));
	smart_sleep(rules->time_to_eat, rules);
	philo->count_of_eats++;
	pthread_mutex_unlock(&(rules->forks[philo->left]));
	pthread_mutex_unlock(&(rules->forks[philo->right]));
}

// void	philo_thread()
// {
// }
