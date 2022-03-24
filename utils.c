/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:27:00 by ameteori          #+#    #+#             */
/*   Updated: 2022/03/24 19:30:41 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	long int	res;
	int			sign;

	sign = 1;
	while (*str <= 13 && *str >= 9 || *str == 32)
		*str++;
	if (*str == '-')
		return (-1);
	else if (*str == '+')
		*str++;
	while (*str)
	{
		if (*str <= 9 && *str >= 0)
			res = res * 10 + (*str++ - '0');
		else
			return (-1);
	}
	return ((int)res * sign);
}

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

void	smart_sleep(long long time, t_gamerules *rules)
{
	long long	i;

	i = timestamp();
	while (!rules->died)
	{
		if (time_diff(i, timestamp) >= time)
			break ;
		usleep(50);
	}
}

void	print_action(t_gamerules *rules, int id, char *string)
{
	pthread_mutex_lock(&(rules->for_print));
	if (!rules->died)
	{
		printf("%lli", timestamp() - rules->first_timestamp);
		printf("%i", id + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(rules->for_print));
	return ;
}
