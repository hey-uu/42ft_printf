/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_integer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:43:24 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/08/06 10:23:22 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(long n, int base_len, t_option *opt)
{
	int	len;

	if (n == 0 && opt->precision == 0 && (opt->flag & 040) == 040)
		return (0);
	len = (n == 0);
	while (n != 0)
	{
		n /= base_len;
		len++;
	}
	if (opt->precision > len)
		return (opt->precision);
	return (len);
}

int	ft_unbrlen(unsigned long n, int base_len, t_option *opt)
{
	int	len;

	if (n == 0 && opt->precision == 0 && (opt->flag & 040) == 040)
		return (0);
	len = (n == 0);
	while (n > 0)
	{
		n /= base_len;
		len++;
	}
	if (opt->precision > len)
		return (opt->precision);
	return (len);
}

void	decide_nbr_sign(t_option *opt, long nbr, int nbr_len)
{
	int	idx;

	if ((opt->flag & 01) == 01 || \
		((nbr < 0 || (opt->flag & 06) != 0) && (opt->flag & 060) == 020))
		idx = 0;
	else
		idx = opt->len - nbr_len - 1;
	if (nbr < 0)
		opt->out[idx] = '-';
	else if ((opt->flag & 02) == 02)
		opt->out[idx] = '+';
	else if ((opt->flag & 04) == 04)
		opt->out[idx] = ' ';
}

void	decide_xunbr_hash(t_option *opt, int xunbr_len, int upper)
{
	int	idx;

	if ((opt->flag & 01) == 01 || \
		((opt->flag & 10) != 0 && (opt->flag & 060) == 020))
		idx = 0;
	else
		idx = opt->len - xunbr_len - 2;
	if ((opt->flag & 010) == 010)
	{
		opt->out[idx] = '0';
		opt->out[idx + 1] = 'x' * (upper == 0) + 'X' * (upper == 1);
	}
}

void	unbrtostr(char *str_nbr, unsigned long nbr, int nbr_len, char *base)
{
	const int	base_len = ft_strlen(base);

	while (nbr != 0 && (--nbr_len) >= 0)
	{	
		str_nbr[nbr_len] = base[nbr % base_len];
		nbr /= base_len;
	}
	while (--nbr_len >= 0)
		str_nbr[nbr_len] = '0';
}
