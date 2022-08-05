/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:44:23 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/08/05 20:15:00 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_identifier(const char *format, int *i, va_list ap)
{
	const t_fct	put[9] = {put_chr, put_str, put_ptr, put_nbr, put_nbr, put_unbr, \
						put_xunbr_lower, put_xunbr_upper, put_percent};
	t_option	opt;
	int			res;

	init_option(&opt);
	while (find_flag(format[++(*i)], &opt.flag))
		;
	while (ft_isdigit(format[*i]))
		opt.width = opt.width * 10 + format[(*i)++] - '0';
	if (format[*i] == '.')
	{
		opt.flag |= 1 << 5;
		while (ft_isdigit(format[++(*i)]))
			opt.precision = opt.precision * 10 + format[*i] - '0';
	}
	if ((opt.flag & 021) == 021)
		opt.padding = '0';
	res = put[find_identifier(format[*i])](&opt, ap);
	free(opt.out);
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			tem;
	int			res;

	va_start(ap, format);
	res = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
			tem = print_identifier(format, &i, ap);
		else
			tem = write(1, format + i, 1);
		if (tem < 0)
			return (-1);
		res += tem;
	}
	va_end(ap);
	return (res);
}
