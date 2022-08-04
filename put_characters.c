/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_characters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:07:39 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/08/04 22:56:56 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	put_percent(t_option *opt, va_list ap)
{
	int	res;

	if (!ap)
		return (-1);
	res = opt->width;
	while (--opt->width > 0)
		if (write(1, " ", 1) < 0)
			return (-1);
	if (write(1, "%", 1) < 0)
		return (-1);
	if (!res)
		res = 1;
	return (res);
}

int	put_chr(t_option *opt, va_list ap)
{
	char	c;
	int		res;

	opt = 0;
	c = (char) va_arg(ap, int);
	res = opt->width;
	while (--opt->width > 0)
		if (write(1, " ", 1) < 0)
			return (-1);
	if (write(1, &c, 1) < 0)
		return (-1);
	if (!res)
		res = 1;
	return (res);
}

int	put_str(t_option *opt, va_list ap)
{
	int		res;
	char	*str;
	char	str_len;

	str = va_arg(ap, char *);
	str_len = ft_strlen(str);
	if (str_len > opt->precision)
		str_len = opt->precision;
	if (str_len < opt->width)
		res = opt->width;
	else
		res = str_len;
	while (opt->width-- > str_len)
		if (write(1, " ", 1) < 0)
			return (-1);
	if (write(1, str, str_len) < 0)
		return (-1);
	return (res);
}