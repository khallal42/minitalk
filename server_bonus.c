/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:18:56 by khallal           #+#    #+#             */
/*   Updated: 2022/12/10 11:11:49 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int sin)
{
	static char	k;
	static int	i;

	k |= (sin == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		ft_putchar(k);
		k = 0;
	}
	else
		k = k << 1;
}

int	main(void)
{
	ft_putstr("PID : ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	while (1)
		pause();
	return (0);
}
