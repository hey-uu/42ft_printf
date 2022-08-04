/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:31:35 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/08/04 22:52:45 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	const char	*str2 = NULL;
	const char	*str1 = "This is hell...";
	int			res;
	
	printf("===================================== %%s ===================================\n");
	printf("==================== case1 : char * 'This is hell...' =======================\n");
	printf("#1 : (warning) flag +\n");
	res = printf("%+s", str1);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#2 : flag -\n");
	res = printf("%-s", str1);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#3 : (warning) flag (blank)\n");
	res = printf("% s", str1);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#4 : (warning) flag  #\n");
	res = printf("%#s", str1);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#5 : (warning) flag 0\n");
	res = printf("%0s", str1);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#6 : flag .\n");
	res = printf("%.s", str1);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#7 : width(1)\n");
	res = printf("%1s", str1);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#8 : width(10)\n");
	res = printf("%10s", str1);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#9 : width(20)\n");
	res = printf("%20s", str1);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#10 : precision(.1)\n");
	res = printf("%.1s", str1);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#11 :  presision(.10)\n");
	res = printf("%.10s", str1);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#12 :  presision(.20)\n");
	res = printf("%.20s", str1);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#13 : width & precision (1.)\n");
	res = printf("%1.s", str1);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#14 : width & precision (1.10)\n");
	res = printf("%1.10s", str1);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#15 : width & precision(1.20)\n");
	res = printf("%1.20s", str1);
	printf("\n>> res value : %d <<\n\n", res);
	
	printf("#16 : width & precision(10.1)\n");
	res = printf("%10.1s", str1);
	printf("\n>> res value : %d << \n\n", res);

	printf("#16 : width & precision(10.10)\n");
	res = printf("%10.10s", str1);
	printf("\n>> res value : %d << \n\n", res);

	printf("#16 : width & precision(10.20)\n");
	res = printf("%10.20s", str1);
	printf("\n>> res value : %d << \n\n", res);

	printf("#16 : width & precision(20.1)\n");
	res = printf("%20.1s", str1);
	printf("\n>> res value : %d << \n\n", res);

	printf("#16 : width & precision(20.10)\n");
	res = printf("%20.10s", str1);
	printf("\n>> res value : %d << \n\n", res);

	printf("#16 : width & precision(20.20)\n");
	res = printf("%20.20s", str1);
	printf("\n>> res value : %d << \n\n", res);

	printf("==================== case1 : char * NULL ===============================\n");
	printf("#1 : (warning) flag +\n");
	res = printf("%+s", str2);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#2 : flag -\n");
	res = printf("%-s", str2);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#3 : (warning) flag (blank)\n");
	res = printf("% s", str2);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#4 : (warning) flag  #\n");
	res = printf("%#s", str2);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#5 : (warning) flag 0\n");
	res = printf("%0s", str2);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#6 : flag .\n");
	res = printf("%.s", str2);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#7 : width(1)\n");
	res = printf("%1s", str2);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#8 : width(10)\n");
	res = printf("%10s", str2);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#9 : width & precision (1.)\n");
	res = printf("%1.s", str2);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#10 : precision(.10)\n");
	res = printf("%.10s", str2);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#11 : precision(.1)\n");
	res = printf("%.1s", str2);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#12 : width & precision(10.20)\n");
	res = printf("%10.20s", str2);
	printf("\n>> res value : %d <<\n\n\n", res);
}