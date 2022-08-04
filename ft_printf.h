/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:40:45 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/08/04 19:53:27 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_option
{
	unsigned char	flag;
	int				width;
	int				precision;
	unsigned char	identifier;
	char			*buff;
}	t_option;

typedef int	(*t_fct)(t_option *, va_list);


int	ft_printf(const char *format, ...);

#endif