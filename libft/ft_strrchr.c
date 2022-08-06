/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:07:48 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/07/20 09:16:05 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	new_c = (char) c;
	size_t		i;
	char		*pos;

	i = 0;
	pos = NULL;
	while (s[i])
	{
		if (s[i] == new_c)
			pos = (char *)(s + i);
		i++;
	}
	if (!new_c)
		return ((char *)(s + i));
	return (pos);
}
