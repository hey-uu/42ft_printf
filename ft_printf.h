/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:40:45 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/08/05 21:55:43 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

# define FT_NULL (void *) 0

typedef struct s_option
{
	unsigned char	flag;
	int				width;
	int				precision;
	int				padding;
	char			*out;
}	t_option;

typedef int	(*t_fct)(t_option *, va_list);

int		ft_printf(const char *format, ...);
void	init_option(t_option *opt);
int		find_flag(const char c, unsigned char *flag);
int		ft_isdigit(int c);
int		find_identifier(const char c);
char	*ft_strdup(const char *s1);

int		put_percent(t_option *opt, va_list ap);
int		put_chr(t_option *opt, va_list ap);
int		put_str(t_option *opt, va_list ap);
void	fill_str(t_option *opt, const char *str, int out_len, int str_len);

int		put_nbr(t_option *opt, va_list ap);
int		put_unbr(t_option *opt, va_list ap);
int		put_ptr(t_option *opt, va_list ap);
int		put_xunbr_lower(t_option *opt, va_list ap);
int		put_xunbr_upper(t_option *opt, va_list ap);

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);
int		ft_nbrlen(long n, int base_len, int precision);
int		ft_unbrlen(unsigned long n, int base_len, int precision);
void	unbrtostr(char *str_nbr, unsigned long nbr, int nbr_len, char *base);
void	decide_integer_sign(t_option *opt, int idx, long nbr);

#endif