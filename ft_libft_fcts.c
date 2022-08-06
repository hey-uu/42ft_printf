/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 10:16:24 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/08/06 10:22:40 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

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
