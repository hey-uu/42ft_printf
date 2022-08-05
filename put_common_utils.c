/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_common_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:43:24 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/08/05 21:47:28 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	unsigned char		*ptr;
	const unsigned char	new_c = (unsigned char) c;

	ptr = (unsigned char *) b;
	i = 0;
	while (i < len)
		ptr[i++] = new_c;
	return (b);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;

	if (!dst && !src)
		return (FT_NULL);
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_nbrlen(long n, int base_len, int precision)
{
	int	len;

	len = (n == 0);
	while (n != 0)
	{
		n /= base_len;
		len++;
	}
	if (precision > len)
		return (precision);
	return (len);
}

int	ft_unbrlen(unsigned long n, int base_len, int precision)
{
	int	len;

	len = (n == 0);
	while (n > 0)
	{
		n /= base_len;
		len++;
	}
	if (precision > len)
		return (precision);
	return (len);
}

void	unbrtostr(char *str_nbr, unsigned long nbr, int nbr_len, char *base)
{
	const int	base_len = ft_strlen(base);

	while (nbr != 0)
	{	
		str_nbr[--nbr_len] = base[nbr % base_len];
		nbr /= base_len;
	}
	while (--nbr_len >= 0)
		str_nbr[nbr_len] = '0';
}

void	decide_integer_sign(t_option *opt, int idx, long nbr)
{
	if (nbr < 0)
		opt->out[idx] = '-';
	else if ((opt->flag & 01) == 01)
		opt->out[idx] = '+';
	else if ((opt->flag & 02) == 02)
		opt->out[idx] = ' ';
}