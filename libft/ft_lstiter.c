/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:30:39 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/07/15 17:38:51 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tem;

	if (!lst || !f)
		return ;
	while (lst)
	{
		tem = lst;
		lst = lst->next;
		f(tem->content);
	}
}
