/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:53:47 by ameteori          #+#    #+#             */
/*   Updated: 2022/03/29 17:50:13 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	write_error(char *str)
{
	printf("ERROR: %s\n", str);
	return (1);
}

int	error_manager(int error)
{
	if (error == 1)
		return (write_error("Bad args"));
	if (error == 2)
		return (write_error("Mutex error"));
	return (1);
}
