/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:16:41 by donghwik          #+#    #+#             */
/*   Updated: 2021/08/25 17:02:46 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

#include <stdio.h>

void	get_bit(int signal)
{
	static char	temp;
	static int	length;
	static int	bit_cnt;
	static char s[100];

	if (length == 100)
	{
		ft_putstr_fd(s, 1);
		ft_memset_custom(s, '\0', 100, &length);
	}
	temp = (temp << 1) + (signal - 30);
	if (++bit_cnt == 7)
	{
		bit_cnt = 0;
		if (temp == 127)
		{
			ft_putstr_fd(s, 1);
			ft_memset_custom(s, '\0', 100, &length);
			temp = 0;
			return ;
		}
		s[length++] = temp;
		temp = 0;
	}
}

int		main(void)
{
	pid_t	pid;
	
	pid = getpid();
	ft_putnbr_fd((int)pid, 1);
	ft_putstr_fd(" <= server pid\n", 1);
	while (1)
	{
		signal(SIGUSR1, get_bit);
		signal(SIGUSR2, get_bit);
	}
	return (0);
}