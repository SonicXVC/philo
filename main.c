/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:48:56 by ameteori          #+#    #+#             */
/*   Updated: 2022/03/30 15:33:38 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	int	ret;
	t_gamerules	rules;
	
	if (ac != 5 && ac != 6)
		return (write_error("Wrong amount of args"));
	ret = general_init(&rules, av);
	if (ret)
		return (error_manager(ret));
	if (game(&rules))
		return (write_error("Error, while trying to initiate Threads"));
	return (0);

}