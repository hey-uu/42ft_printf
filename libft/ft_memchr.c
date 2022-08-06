/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:42:49 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/07/20 09:19:40 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*s2;
	const unsigned char	new_c = (unsigned char) c;

	s2 = (unsigned char *) s;
	i = 0;
	while ((i < n) && (s2[i] != new_c))
		i++;
	if (i == n)
		return (FT_NULL);
	return ((void *) s2 + i);
}
