/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_integers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:09:39 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/08/05 22:30:41 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_nbr(t_option *opt, va_list ap)
{
	long	nbr;
	int		nbr_len;
	int		out_len;

	nbr = (long) va_arg(ap, int);
	nbr_len = ft_nbrlen(nbr, 10, opt->precision);
	out_len = (nbr < 0 || (opt->flag & 06) != 0);
	out_len += (opt->width > nbr_len) * opt->width + \
				(opt->width <= nbr_len) * nbr_len;
	opt->out = malloc(out_len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, out_len);
	decide_integer_sign(opt, out_len - nbr_len - 1, nbr);
	if (nbr < 0)
		nbr *= -1;
	if ((opt->flag & 01) == 01)
		unbrtostr(opt->out, (unsigned long) nbr, nbr_len, "0123456789");
	else
		unbrtostr(opt->out + out_len - nbr_len, (unsigned long) nbr, \
				nbr_len, "0123456789");
	return (write(1, opt->out, out_len));
}

int	put_unbr(t_option *opt, va_list ap)
{
	const unsigned int	unbr = va_arg(ap, unsigned int);
	int					unbr_len;
	int					out_len;

	unbr_len = ft_unbrlen(unbr, 10, opt->precision);
	out_len = (opt->width > unbr_len) * opt->width + \
				(opt->width <= unbr_len) * unbr_len;
	opt->out = malloc(out_len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, out_len);
	if ((opt->flag & 01) == 01)
		unbrtostr(opt->out, (unsigned long) unbr, unbr_len, "0123456789");
	else
		unbrtostr(opt->out + out_len - unbr_len, (unsigned long) unbr, \
					unbr_len, "0123456789");
	return (write(1, opt->out, out_len));
}

int	put_ptr(t_option *opt, va_list ap)
{
	const unsigned long	ptr = (unsigned long) va_arg(ap, void *);
	int					ptr_len;
	int					out_len;

	ptr_len = ft_unbrlen(ptr, 16, opt->precision);
	out_len = 2 + opt->width * (opt->width > ptr_len) + \
					ptr_len * (opt->width <= ptr_len);
	opt->out = malloc(out_len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, out_len);
	ft_memcpy(opt->out + out_len - ptr_len - 2, "0x", 2);
	if ((opt->flag & 01) == 01)
		unbrtostr(opt->out + 2, ptr, ptr_len, "0123456789abcdef");
	else
		unbrtostr(opt->out + out_len - ptr_len, ptr, ptr_len, \
				"0123456789abcdef");
	return (write(1, opt->out, out_len));
}

int	put_xunbr_lower(t_option *opt, va_list ap)
{
	const unsigned int	xunbr = va_arg(ap, unsigned int);
	int					xunbr_len;
	int					out_len;

	xunbr_len = ft_unbrlen(xunbr, 16, opt->precision);
	out_len = opt->width * (opt->width > xunbr_len) + \
				xunbr_len * (opt->width <= xunbr_len) + \
				2 * ((opt->flag & 010) == 010);
	opt->out = malloc(out_len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, out_len);
	if ((opt->flag & 010) == 010)
		ft_memcpy(opt->out + out_len - xunbr_len - 2, "0x", 2);
	if ((opt->flag & 01) == 01)
		unbrtostr(opt->out, xunbr, xunbr_len, "0123456789abcdef");
	else
		unbrtostr(opt->out + out_len - xunbr_len, xunbr, xunbr_len, \
				"0123456789abcdef");
	return (write(1, opt->out, out_len));
}

int	put_xunbr_upper(t_option *opt, va_list ap)
{
	const unsigned int	xunbr = va_arg(ap, unsigned int);
	int					xunbr_len;
	int					out_len;

	xunbr_len = ft_unbrlen(xunbr, 16, opt->precision);
	out_len = opt->width * (opt->width > xunbr_len) + \
				xunbr_len * (opt->width <= xunbr_len) + \
				2 * ((opt->flag & 010) == 010);
	opt->out = malloc(out_len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, out_len);
	if ((opt->flag & 010) == 010)
		ft_memcpy(opt->out + out_len - xunbr_len - 2, "0X", 2);
	if ((opt->flag & 01) == 01)
		unbrtostr(opt->out, xunbr, xunbr_len, "0123456789ABCDEF");
	else
		unbrtostr(opt->out + out_len - xunbr_len, xunbr, xunbr_len, \
				"0123456789ABCDEF");
	return (write(1, opt->out, out_len));
}
