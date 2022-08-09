/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_characters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:07:39 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/08/09 12:14:50 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft/libft.h"

static void	fill_str(t_option *opt, const char *str, int str_len);

int	put_percent(t_option *opt, va_list ap)
{
	if (!ap)
		return (-1);
	opt->len = opt->width + (opt->width == 0);
	opt->out = malloc(opt->len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, opt->len);
	if ((opt->flag & 01) == 01)
		opt->out[0] = '%';
	else
		opt->out[opt->len - 1] = '%';
	return (write(1, opt->out, opt->len));
}

int	put_chr(t_option *opt, va_list ap)
{
	const char	c = (char) va_arg(ap, int);

	opt->len = opt->width + (opt->width == 0);
	opt->out = malloc(opt->len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, opt->len);
	if ((opt->flag & 01) == 01)
		opt->out[0] = c;
	else
		opt->out[opt->len - 1] = c;
	return (write(1, opt->out, opt->len));
}

int	put_str(t_option *opt, va_list ap)
{
	const char	*str = va_arg(ap, char *);
	int			str_len;

	if (!str)
		str_len = 6;
	else
		str_len = ft_strlen(str);
	if ((opt->flag & 040) == 040 && str_len > opt->precision)
		str_len = opt->precision;
	opt->len = (str_len < opt->width) * opt->width + \
				(str_len >= opt->width) * str_len;
	opt->out = malloc(opt->len);
	if (!opt->out)
		return (-1);
	fill_str(opt, str, str_len);
	return (write(1, opt->out, opt->len));
}

static void	fill_str(t_option *opt, const char *str, int str_len)
{
	ft_memset(opt->out, opt->padding, opt->len);
	if ((opt->flag & 01) == 01)
	{
		if (!str)
			ft_memcpy(opt->out, "(null)", str_len);
		else
			ft_memcpy(opt->out, str, str_len);
	}
	else
	{
		if (!str)
			ft_memcpy(opt->out + opt->len - str_len, "(null)", str_len);
		else
			ft_memcpy(opt->out + opt->len - str_len, str, str_len);
	}
}
