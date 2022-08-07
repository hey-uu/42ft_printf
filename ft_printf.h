/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 10:37:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/08/06 10:44:52 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_option
{
	unsigned char	flag;
	int				width;
	int				precision;
	int				padding;
	char			*out;
	int				len;
}	t_option;

typedef int	(*t_fct)(t_option *, va_list);

int		ft_printf(const char *format, ...);

int		put_percent(t_option *opt, va_list ap);
int		put_chr(t_option *opt, va_list ap);
int		put_str(t_option *opt, va_list ap);
int		put_nbr(t_option *opt, va_list ap);
int		put_unbr(t_option *opt, va_list ap);
int		put_ptr(t_option *opt, va_list ap);
int		put_xunbr_lower(t_option *opt, va_list ap);
int		put_xunbr_upper(t_option *opt, va_list ap);

int		ft_nbrlen(long n, int base_len, t_option *opt);
int		ft_unbrlen(unsigned long n, int base_len, t_option *opt);
void	decide_nbr_sign(t_option *opt, long nbr, int nbr_len);
void	decide_xunbr_hash(t_option *opt, int xunbr_len, int upper);
void	unbrtostr(char *str_nbr, unsigned long nbr, int nbr_len, char *base);

#endif
