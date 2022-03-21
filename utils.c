/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:27:00 by ameteori          #+#    #+#             */
/*   Updated: 2022/03/18 16:38:00 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(char *str)
{
	long int	res;
	int			sign;
	
	sign = 1;
	while (*str <= 13 && *str >= 9 || *str == 32)
		*str++;
	if (*str == '-')
		return (-1);
	if else (*str == '+')
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

