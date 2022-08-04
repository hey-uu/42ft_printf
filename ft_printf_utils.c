/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:30:45 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/08/04 20:02:08 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_option(t_option *opt)
{
	opt->flag = 0;
	opt->width = 0;
	opt->precision = 0;
	opt->identifier = 0;
	opt->buff = 0;
}

int	find_flag(const char c, int *flag)
{
	const char	flags[5] = {'-', '+', ' ', '#', '0'};
	int			i;

	i = -1;
	while (++i < 5)
	{
		if (flags[i] == c)
		{
			*flag |= 1 << i;
			return (1);
		}
	}
	return (0);
}

int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int	find_identifier(const char c)
{
	const char	identifiers[9] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%'};
	int			i;

	i = -1;
	while (++i < 9)
		if (identifiers[i] == c)
			return (i);
	return (-1);
}
