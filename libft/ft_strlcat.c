/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:53:54 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/07/20 08:16:09 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	const size_t	destlen = ft_strlen(dest);
	const size_t	srclen = ft_strlen(src);
	size_t			i;

	if (size <= destlen)
		return (srclen + size);
	i = 0;
	while (i < size - destlen - 1 && src[i])
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
