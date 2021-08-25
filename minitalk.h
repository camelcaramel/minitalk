/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:17:11 by donghwik          #+#    #+#             */
/*   Updated: 2021/08/25 17:01:15 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

typedef struct	s_mesaage
{
	unsigned int	length;
	unsigned int	bit_cnt;
	char			temp;
	char			s[100];
}				t_message;

void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);
void		*ft_memset_custom(void *b, int c, size_t len, int *length);
void		get_bit(int bit);
#endif