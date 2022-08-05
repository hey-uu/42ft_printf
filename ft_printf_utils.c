/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:30:45 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/08/05 20:57:06 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_option(t_option *opt)
{
	opt->flag = 0;
	opt->width = 0;
	opt->precision = 0;
	opt->padding = ' ';
	opt->out = 0;
}

int	find_flag(const char c, unsigned char *flag)
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

int	ft_isdigit(int c)
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

char	*ft_strdup(const char *s1)
{
	const size_t	len = ft_strlen(s1);
	char			*new_str;
	size_t			i;

	new_str = malloc(len + 1);
	if (!new_str)
		return (FT_NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}