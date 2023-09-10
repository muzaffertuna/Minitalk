/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:08:37 by mtoktas           #+#    #+#             */
/*   Updated: 2023/09/10 20:00:52 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handlesignal(int sign)
{
	static int	bit;
	static int	set;

	if (sign == SIGUSR1)
		set += 1 << bit;
	if (bit == 7)
	{
		write(1, &set, 1);
		bit = 0;
		set = 0;
	}
	else
		bit++;
}

void	putnbr(int n)
{
	char	c;

	if (n < 10)
	{
		c = n + 48;
		write(1, &c, 1);
	}
	else if (n > 9)
	{
		putnbr(n / 10);
		putnbr(n % 10);
	}
}

int	main(int ac, char **av)
{
	int		p_id;

	(void) av;
	if (ac == 1)
	{
		p_id = getpid();
		putnbr(p_id);
		write(1, "\n", 1);
		signal(SIGUSR1, handlesignal);
		signal(SIGUSR2, handlesignal);
		while (1)
			pause();
	}
	else
		printf("No need argument.\n");
}
