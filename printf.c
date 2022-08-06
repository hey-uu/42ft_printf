/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:44:23 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/08/06 10:44:19 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	init_option(t_option *opt)
{
	opt->flag = 0;
	opt->width = 0;
	opt->precision = 0;
	opt->padding = ' ';
	opt->out = 0;
	opt->len = 0;
}

static int	find_flag(const char c, unsigned char *flag)
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

static int	find_identifier(const char c)
{
	const char	identifiers[9] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%'};
	int			i;

	i = -1;
	while (++i < 9)
		if (identifiers[i] == c)
			return (i);
	return (-1);
}

static int	print_identifier(const char *format, int *i, va_list ap)
{
	const t_fct	put[9] = {put_chr, put_str, put_ptr, put_nbr, put_nbr, \
					put_unbr, put_xunbr_lower, put_xunbr_upper, put_percent};
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
	if ((opt.flag & 061) == 020)
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
