/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_unbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:30:16 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/08/05 19:44:13 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int					res;
	unsigned int		i;
	const unsigned int	num = 2147483647;

	printf("=========test of %%u ===========\n");
	i = 1;
	printf("#%u : (warning) flag +\n", i++);
	res = printf("%+u", num);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#%u : flag -\n", i++);
	res = printf("%-u", num);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#%u : (warning) flag (blank)\n", i++);
	res = printf("% u", num);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#%u : (warning) flag + & (blank)\n", i++);
	res = printf("%+ u", num);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#%u : (warning) flag #\n", i++);
	res = printf("%#u", num);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#%u : flag 0\n", i++);
	res = printf("%0u", num);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#%u : width(5) \n", i++);
	res = printf("%5u", num);
	printf("\nres value : %d\n\n", res);

	printf("#%u : width(10)\n", i++);
	res = printf("%10u", num);
	printf("\nres value : %d\n\n", res);

	printf("#%u : width(15)\n", i++);
	res = printf("%15u", num);
	printf("\nres value : %d\n\n", res);

	printf("#%u : flag(0) & width(15)\n", i++);
	res = printf("%015u", num);
	printf("\nres value : %d\n\n", res);

	printf("#%u : precision(.)\n", i++);
	res = printf("%.u", num);
	printf("\nres value : %d\n\n", res);

	printf("#%u : precision(.5)\n", i++);
	res = printf("%.5u", num);
	printf("\nres value : %d\n\n", res);

	printf("#%u : precision(.10)\n", i++);
	res = printf("%.10u", num);
	printf("\nres value : %d\n\n", res);

	printf("#%u : precision(.15)\n", i++);
	res = printf("%.15u", num);
	printf("\nres value : %d\n\n", res);

	printf("#%u : width & precision(5.)\n", i++);
	res = printf("%5.u", num);
	printf("\nres value : %d\n\n", res);

	printf("#%u : width & precision(5.5)\n", i++);
	res = printf("%5.5u", num);
	printf("\nres value : %d\n\n", res);

	printf("#%u : width & precision(5.10)\n", i++);
	res = printf("%5.10u", num);
	printf("\nres value : %d\n\n", res);

	printf("#%u : width & precision(5.15)\n", i++);
	res = printf("%5.15u", num);
	printf("\nres value : %d\n\n", res);

	printf("#%u : width & precision(10.5)\n", i++);
	res = printf("%10.5u", num);
	printf("\nres value : %d\n\n", res);

	printf("#%u : width & precision(10.10)\n", i++);
	res = printf("%10.10u", num);
	printf("\nres value : %d\n\n", res);

	printf("#%u : width & precision(10.20)\n", i++);
	res = printf("%10.20u", num);
	printf("\nres value : %d\n\n", res);

	printf("#%u : width & precision(20.5)\n", i++);
	res = printf("%20.5u", num);
	printf("\nres value : %d\n\n", res);

	printf("#%u : width & precision(20.10)\n", i++);
	res = printf("%20.10u", num);
	printf("\nres value : %d\n\n", res);

	printf("#%u : width & precision(20.10)\n", i++);
	res = printf("%20.10u", num);
	printf("\nres value : %d\n\n", res);

	printf("#%u : width & precision(20.10)\n", i++);
	res = printf("%20.10u", num);
	printf("\nres value : %d\n\n", res);
	
	printf("#%u : (warning) flag(' ') & width & precision(20.10)\n", i++);
	res = printf("% 20.10u", num);
	printf("\nres value : %d\n\n", res);
	
	printf("#%u : (warning) flag('+') & width & precision(20.10)\n", i++);
	res = printf("%+20.10u", num);
	printf("\nres value : %d\n\n", res);
	
	printf("#%u : (warning) flag('+') & width & precision(20.20)\n", i++);
	res = printf("%+20.20u", num);
	printf("\nres value : %d\n\n", res);

	printf("#%u : precision(neither with number or *)\n", i++);
	res = printf("%.u", num);
	printf("\nres value : %d\n\n", res);
}
