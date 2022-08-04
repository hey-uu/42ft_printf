/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:30:16 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/08/04 22:30:59 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int			res;
	const int	num = 123;

	printf("=========test of %%d ===========\n");

	printf("#7 : width \n");
	res = printf("%10d", num);
	printf("\nres value : %d\n\n", res);

	printf("#8 : precision\n");
	res = printf("%.10d", num);
	printf("\nres value : %d\n\n", res);

	printf("#9 : width(10) < precision(20)\n");
	res = printf("%10.20d", num);
	printf("\nres value : %d\n\n", res);

	printf("#9 : width(20) > precision(10)\n");
	res = printf("%20.10d", num);
	printf("\nres value : %d\n\n", res);

	printf("#10 : precision(neither with number or *)\n");
	res = printf("%.d", num);
	printf("\nres value : %d\n\n", res);

	// incomplete format specifier
	// printf("#11 : error\n");
	// res = printf("%");
	// printf("\nres value : %d\n\n", res);
}
