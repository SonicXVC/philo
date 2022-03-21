/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:53:47 by ameteori          #+#    #+#             */
/*   Updated: 2022/03/18 19:05:07 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_manager(int error)
{
	if (error == 1)
		write(1, "Bad args\n", 9);
	if (error == 2)
		write(1, "Mutex error\n", 12);
}