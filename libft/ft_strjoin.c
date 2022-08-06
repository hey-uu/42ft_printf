/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:57:41 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/07/20 08:15:55 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_str;

	if (!s1 || !s2)
		return (FT_NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 >= FT_SIZE_MAX - len2)
		return (FT_NULL);
	new_str = (char *)malloc(len1 + len2 + 1);
	if (!new_str)
		return (FT_NULL);
	ft_strlcpy(new_str, s1, len1 + 1);
	ft_strlcpy(new_str + len1, s2, len2 + 1);
	return (new_str);
}
