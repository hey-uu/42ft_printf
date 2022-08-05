/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:30:16 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/08/05 15:04:52 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int			res;
	int			i;
	const int	num = 2147483647;

	printf("=========test of %%d ===========\n");
	i = 1;
	printf("#%d : flag +\n", i++);
	res = printf("%+d", num);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#%d : flag -\n", i++);
	res = printf("%-d", num);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#%d : flag (blank)\n", i++);
	res = printf("% d", num);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#%d : (warning) flag + & (blank)\n", i++);
	res = printf("%+ d", num);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#%d : (warning) flag  #\n", i++);
	res = printf("%#d", num);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#%d : flag 0\n", i++);
	res = printf("%0d", num);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#%d : width(5) \n", i++);
	res = printf("%5d", num);
	printf("\nres value : %d\n\n", res);

	printf("#%d : width(10)\n", i++);
	res = printf("%10d", num);
	printf("\nres value : %d\n\n", res);

	printf("#%d : width(15)\n", i++);
	res = printf("%15d", num);
	printf("\nres value : %d\n\n", res);

	printf("#%d : flag(0) & width(15)\n", i++);
	res = printf("%015d", num);
	printf("\nres value : %d\n\n", res);

	printf("#%d : precision(.)\n", i++);
	res = printf("%.d", num);
	printf("\nres value : %d\n\n", res);

	printf("#%d : precision(.5)\n", i++);
	res = printf("%.5d", num);
	printf("\nres value : %d\n\n", res);

	printf("#%d : precision(.10)\n", i++);
	res = printf("%.10d", num);
	printf("\nres value : %d\n\n", res);

	printf("#%d : precision(.15)\n", i++);
	res = printf("%.15d", num);
	printf("\nres value : %d\n\n", res);

	printf("#%d : width & precision(5.)\n", i++);
	res = printf("%5.d", num);
	printf("\nres value : %d\n\n", res);

	printf("#%d : width & precision(5.5)\n", i++);
	res = printf("%5.5d", num);
	printf("\nres value : %d\n\n", res);

	printf("#%d : width & precision(5.10)\n", i++);
	res = printf("%5.10d", num);
	printf("\nres value : %d\n\n", res);

	printf("#%d : width & precision(5.15)\n", i++);
	res = printf("%5.15d", num);
	printf("\nres value : %d\n\n", res);

	printf("#%d : width & precision(10.5)\n", i++);
	res = printf("%10.5d", num);
	printf("\nres value : %d\n\n", res);

	printf("#%d : width & precision(10.10)\n", i++);
	res = printf("%10.10d", num);
	printf("\nres value : %d\n\n", res);

	printf("#%d : width & precision(10.20)\n", i++);
	res = printf("%10.20d", num);
	printf("\nres value : %d\n\n", res);

	printf("#%d : width & precision(20.5)\n", i++);
	res = printf("%20.5d", num);
	printf("\nres value : %d\n\n", res);

	printf("#%d : width & precision(20.10)\n", i++);
	res = printf("%20.10d", num);
	printf("\nres value : %d\n\n", res);

	printf("#%d : width & precision(20.10)\n", i++);
	res = printf("%20.10d", num);
	printf("\nres value : %d\n\n", res);

	printf("#%d : width & precision(20.10)\n", i++);
	res = printf("%20.10d", num);
	printf("\nres value : %d\n\n", res);
	
	printf("#%d : flag(' ') & width & precision(20.10)\n", i++);
	res = printf("% 20.10d", num);
	printf("\nres value : %d\n\n", res);
	
	printf("#%d : flag('+') & width & precision(20.10)\n", i++);
	res = printf("%+20.10d", num);
	printf("\nres value : %d\n\n", res);
	
	printf("#%d : flag('+') & width & precision(20.20)\n", i++);
	res = printf("%+20.20d", num);
	printf("\nres value : %d\n\n", res);

	printf("#%d : precision(neither with number or *)\n", i++);
	res = printf("%.d", num);
	printf("\nres value : %d\n\n", res);
}
