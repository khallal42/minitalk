/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:17:35 by khallal           #+#    #+#             */
/*   Updated: 2022/12/10 11:55:46 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_bits(int sin, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (1 & (c >> i))
		{
			if (kill(sin, SIGUSR1) == -1)
				exit(0);
		}
		else if (c)
		{
			if (kill(sin, SIGUSR2) == -1)
				exit(0);
		}
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3 && ft_strlen(av[2]) != 0)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			send_bits(pid, av[2][i]);
			i++;
		}
		send_bits(pid, '\n');
	}
	else
	{
		ft_putstr("(SOMTHING IS WRONG)Enter after ./a.out : PID & the message");
		exit(1);
	}
	return (0);
}
