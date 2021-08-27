/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:24:09 by donghwik          #+#    #+#             */
/*   Updated: 2021/08/27 21:32:03 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	write_num(unsigned int num, int fd)
{
	if (num / 10 > 0)
		write_num(num / 10, fd);
	write(fd, &"0123456789"[num % 10], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
		num = (-1) * (n);
	else
		num = n;
	if (n < 0)
		write(fd, &"-", 1);
	write_num(num, fd);
}

size_t	ft_strlen(const char *s)
{
	const char	*temp;

	temp = s;
	while (*temp)
		temp++;
	return (temp - s);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
