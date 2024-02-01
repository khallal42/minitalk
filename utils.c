/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:44:43 by khallal           #+#    #+#             */
/*   Updated: 2022/12/08 10:59:38 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *s)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	i = 0;
	sign = 1;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == 45 || s[i] == 43)
	{	
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res * sign);
}

int	ft_strlen(char *h)
{
	int	i;

	i = 0;
	while (h[i])
		i++;
	return (i);
}

void	ft_putstr(char *g)
{
	int	i;

	i = 0;
	while (g[i])
	{
		write(1, &g[i], 1);
		i++;
	}
}

void	ft_putnbr(long nb)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	else
	{
		ft_putchar(nb + '0');
	}
}
