/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_integers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:09:39 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/08/06 10:41:00 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	put_nbr(t_option *opt, va_list ap)
{
	long	nbr;
	int		nbr_len;
	int		sign;

	nbr = (long) va_arg(ap, int);
	nbr_len = ft_nbrlen(nbr, 10, opt);
	sign = (nbr < 0 || (opt->flag & 06) != 0);
	opt->len = (opt->width > nbr_len + sign) * opt->width + \
				(opt->width <= nbr_len + sign) * (nbr_len + sign);
	opt->out = malloc(opt->len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, opt->len);
	decide_nbr_sign(opt, nbr, nbr_len);
	if (nbr < 0)
		nbr *= -1;
	if ((opt->flag & 01) == 01)
		unbrtostr(opt->out + sign, (unsigned long) nbr, nbr_len, "0123456789");
	else
		unbrtostr(opt->out + opt->len - nbr_len, (unsigned long) nbr, \
				nbr_len, "0123456789");
	return (write(1, opt->out, opt->len));
}

int	put_unbr(t_option *opt, va_list ap)
{
	const unsigned int	unbr = va_arg(ap, unsigned int);
	int					unbr_len;

	unbr_len = ft_unbrlen(unbr, 10, opt);
	opt->len = (opt->width > unbr_len) * opt->width + \
				(opt->width <= unbr_len) * unbr_len;
	opt->out = malloc(opt->len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, opt->len);
	if ((opt->flag & 01) == 01)
		unbrtostr(opt->out, (unsigned long) unbr, unbr_len, "0123456789");
	else
		unbrtostr(opt->out + opt->len - unbr_len, (unsigned long) unbr, \
					unbr_len, "0123456789");
	return (write(1, opt->out, opt->len));
}

int	put_ptr(t_option *opt, va_list ap)
{
	const unsigned long	ptr = (unsigned long) va_arg(ap, void *);
	int					ptr_len;

	ptr_len = ft_unbrlen(ptr, 16, opt);
	opt->len = opt->width * (opt->width > ptr_len + 2) + \
					(ptr_len + 2) * (opt->width <= ptr_len + 2);
	opt->out = malloc(opt->len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, opt->len);
	if ((opt->flag & 01) == 01)
	{
		ft_memcpy(opt->out, "0x", 2);
		unbrtostr(opt->out + 2, ptr, ptr_len, "0123456789abcdef");
	}
	else
	{
		ft_memcpy(opt->out + opt->len - ptr_len - 2, "0x", 2);
		unbrtostr(opt->out + opt->len - ptr_len, ptr, ptr_len, \
				"0123456789abcdef");
	}
	return (write(1, opt->out, opt->len));
}

int	put_xunbr_lower(t_option *opt, va_list ap)
{
	const unsigned int	xunbr = va_arg(ap, unsigned int);
	int					xunbr_len;
	int					hash;

	xunbr_len = ft_unbrlen(xunbr, 16, opt);
	hash = ((opt->flag & 010) == 010 && xunbr > 0) * 2;
	opt->len = (opt->width > xunbr_len + hash) * opt->width + \
			(opt->width <= xunbr_len + hash) * (xunbr_len + hash);
	opt->out = malloc(opt->len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, opt->len);
	if (xunbr > 0)
		decide_xunbr_hash(opt, xunbr_len, 0);
	if ((opt->flag & 01) == 01)
		unbrtostr(opt->out + hash, xunbr, xunbr_len, "0123456789abcdef");
	else
		unbrtostr(opt->out + opt->len - xunbr_len, xunbr, xunbr_len, \
				"0123456789abcdef");
	return (write(1, opt->out, opt->len));
}

int	put_xunbr_upper(t_option *opt, va_list ap)
{
	const unsigned int	xunbr = va_arg(ap, unsigned int);
	int					xunbr_len;
	int					hash;

	xunbr_len = ft_unbrlen(xunbr, 16, opt);
	hash = ((opt->flag & 010) == 010 && xunbr > 0) * 2;
	opt->len = (opt->width > xunbr_len + hash) * opt->width + \
			(opt->width <= xunbr_len + hash) * (xunbr_len + hash);
	opt->out = malloc(opt->len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, opt->len);
	if (xunbr > 0)
		decide_xunbr_hash(opt, xunbr_len, 1);
	if ((opt->flag & 01) == 01)
		unbrtostr(opt->out + hash, xunbr, xunbr_len, "0123456789ABCDEF");
	else
		unbrtostr(opt->out + opt->len - xunbr_len, xunbr, xunbr_len, \
				"0123456789ABCDEF");
	return (write(1, opt->out, opt->len));
}
