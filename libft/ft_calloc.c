/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:41:19 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/07/20 07:42:19 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*new;
	size_t			total;
	size_t			i;

	if (count > 0 && size > FT_SIZE_MAX / count)
		return (FT_NULL);
	total = count * size;
	new = malloc(total);
	if (!new)
		return (FT_NULL);
	i = 0;
	while (i < total)
		new[i++] = 0;
	return ((void *) new);
}
