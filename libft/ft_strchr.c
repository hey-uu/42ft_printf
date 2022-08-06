/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:55:56 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/07/20 09:11:01 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	new_c = (char) c;
	size_t		i;

	i = 0;
	while (s[i] && s[i] != new_c)
		i++;
	if (s[i] != new_c)
		return (FT_NULL);
	return ((char *)s + i);
}
