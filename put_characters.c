/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_characters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:07:39 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/08/05 21:17:50 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_percent(t_option *opt, va_list ap)
{
	int	out_len;

	if (!ap)
		return (-1);
	out_len = opt->width + (opt->width == 0);
	opt->out = malloc(out_len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, out_len);
	if ((opt->flag & 01) == 01)
		opt->out[0] = '%';
	else
		opt->out[out_len - 1] = '%';
	return (write(1, opt->out, out_len));
}

int	put_chr(t_option *opt, va_list ap)
{
	const char	c = (char) va_arg(ap, int);
	int			out_len;

	out_len = opt->width + (opt->width == 0);
	opt->out = malloc(out_len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, out_len);
	if ((opt->flag & 01) == 01)
		opt->out[0] = c;
	else
		opt->out[out_len - 1] = c;
	return (write(1, opt->out, out_len));
}

int	put_str(t_option *opt, va_list ap)
{
	const char	*str = va_arg(ap, char *);
	int			str_len;
	int			out_len;

	if (!str)
		str_len = 6;
	else
		str_len = ft_strlen(str);
	if ((opt->flag & 040) == 040 && str_len > opt->precision)
		str_len = opt->precision;
	out_len = (str_len < opt->width) * opt->width + \
				(str_len >= opt->width) * str_len;
	opt->out = malloc(out_len);
	if (!opt->out)
		return (-1);
	fill_str(opt, str, out_len, str_len);
	return (write(1, opt->out, out_len));
}

void	fill_str(t_option *opt, const char *str, int out_len, int str_len)
{
	ft_memset(opt->out, opt->padding, out_len);
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
			ft_memcpy(opt->out + out_len - str_len, "(null)", str_len);
		else
			ft_memcpy(opt->out + out_len - str_len, str, str_len);
	}
}