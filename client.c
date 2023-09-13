/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:11:53 by mtoktas           #+#    #+#             */
/*   Updated: 2023/09/13 13:08:21 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[0] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	int		server_id;

	if (ac == 3)
	{
		server_id = ft_atoi(av[1]);
		i = 0;
		while (av[2][i])
		{
			j = 0;
			while (j != 8)
			{
				if (av[2][i] >> j & 1)
					kill(server_id, SIGUSR1);
				else
					kill(server_id, SIGUSR2);
				usleep(100);
				j++;
			}
			i++;
		}
	}
	else
		write(2, "NOT CORRECT ARGUMENTS\n", 22);
}
