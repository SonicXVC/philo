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
