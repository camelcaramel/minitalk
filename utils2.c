/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:42:54 by donghwik          #+#    #+#             */
/*   Updated: 2021/09/25 15:31:37 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	is_space(char c)
{
	return (c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r' || c == ' ');
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	const char		*sp;
	int				neg;
	int				ret;

	sp = str;
	ret = 0;
	neg = 1;
	while (is_space(*sp))
		sp++;
	if (*sp == '-')
	{
		neg = -1;
		sp++;
	}
	else
	{
		if (*sp == '+')
			sp++;
	}
	while (ft_isdigit(*sp))
		ret = 10 * ret + (*sp++ - '0');
	return (neg * ret);
}

void	*ft_memset_custom(void *b, int c, size_t len, int *length)
{
	unsigned char	*ret;

	ret = b;
	*length = 0;
	while (len--)
		*ret++ = (unsigned char)c;
	return ((void *)b);
}
