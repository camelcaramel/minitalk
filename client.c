/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:18:00 by donghwik          #+#    #+#             */
/*   Updated: 2021/08/25 17:04:54 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int			send_bit(pid_t pid, char c)
{
	int		ret;

	if (c == 0)
		ret = kill(pid, SIGUSR1);
	else
		ret = kill(pid, SIGUSR2);
	usleep(1000);
	return (ret + 1);
}

int			send_char(pid_t pid, char c)
{
	int		radix;

	radix = 6;
	while (radix > -1)
		if (!send_bit(pid, c & (1 << radix--)))
			return (0);
	return (1);
}

int			send_message(pid_t pid, char *msg)
{
	while (*msg >= 32 && *msg <= 126)
		if (!send_char(pid, *msg++))
			return (0);
	return (send_char(pid, 127));
}

int			main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
	{
		ft_putstr_fd("Error : Wrong Usage\n", 1);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 100)
	{
		ft_putstr_fd("Error : Wrong Pid Input\n", 1);
		return (1);
	}
	if (!send_message(pid, argv[2]))
	{	
		ft_putstr_fd("Error : Can't Send Message\n", 1);
		return (1);
	}
	return (0);
}
