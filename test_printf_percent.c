/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_percent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:33:48 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/08/05 09:09:37 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	res;
/* 
	SEG FAULT
	res = printf(NULL);
	printf("res value : %d\n", res);
*/

	printf("=========test of %%%% ===========\n");
	printf("#1 : flag +\n");
	res = printf("%+%");
	printf("\n>> res value : %d <<\n\n", res);

	printf("#2 : flag -\n");
	res = printf("%-%");
	printf("\n>> res value : %d <<\n\n", res);

	printf("#3 : flag (blank)\n");
	res = printf("% %");
	printf("\n>> res value : %d <<\n\n", res);

	printf("#4 : flag  #\n");
	res = printf("%#%");
	printf("\n>> res value : %d <<\n\n", res);

	printf("#5 : flag 0\n");
	res = printf("%0%");
	printf("\n>> res value : %d <<\n\n", res);

	printf("#6 : flag .\n");
	res = printf("%.%");
	printf("\n>> res value : %d <<\n\n", res);

	printf("#7 : width(1) \n");
	res = printf("%1%");
	printf("\n>> res value : %d <<\n\n", res);

	printf("#8 : width(10) \n");
	res = printf("%10%");
	printf("\n>> res value : %d <<\n\n", res);

	printf("#9 : flag(-) & width(10) \n");
	res = printf("%-10%");
	printf("\n>> res value : %d <<\n\n", res);

	printf("#10 : flag(0) & width(10) \n");
	res = printf("%010%");
	printf("\n>> res value : %d <<\n\n", res);

	printf("#11 : flag(-) & flag(0) & width(10) \n");
	res = printf("%-010%");
	printf("\n>> res value : %d <<\n\n", res);

	printf("#8 : precision(.10)\n");
	res = printf("%.10%");
	printf("\n>> res value : %d <<\n\n", res);

	printf("#9 : width(10) & precision(.20)\n");
	res = printf("%10.20%");
	printf("\n>> res value : %d <<\n\n", res);

}
