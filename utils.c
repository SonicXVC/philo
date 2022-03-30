/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:27:00 by ameteori          #+#    #+#             */
/*   Updated: 2022/03/29 18:51:15 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_long(long long int nbr, long long int sign)
{
	if (nbr >= 2147483648)
	{
		if (sign == 1)
			return (-1);
		else if (nbr > 2147483648)
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long long int	i;
	long long int	sign;
	long long int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\f' \
			|| str[i] == '\v' || str[i] == '\r' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
		if (ft_long(nbr, sign) != 1)
			return (ft_long(nbr, sign));
	}
	return ((int)nbr * sign);
}

// int	ft_atoi(char *str)
// {
// 	long int	res;
// 	int			sign;

// 	sign = 1;
// 	while ((*str <= 13 && *str >= 9) || *str == 32)
// 		str++;
// 	if (*str == '-')
// 		return (-1);
// 	else if (*str == '+')
// 		str++;
// 	while (*str)
// 	{
// 		if (*str <= 9 && *str >= 0)
// 			res = res * 10 + (*str++ - '0');
// 		else
// 			return (-1);
// 	}
// 	return ((int)res * sign);
// }

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
		if (time_diff(i, timestamp()) >= time)
			break ;
		usleep(50);
	}
}

void	print_action(t_gamerules *rules, int id, char *string)
{
	pthread_mutex_lock(&(rules->for_print));
	if (!rules->died)
	{
		printf("%lli ", timestamp() - rules->first_timestamp);
		printf("%i ", id + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(rules->for_print));
	return ;
}
