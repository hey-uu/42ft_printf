/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:33:48 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/08/04 22:28:21 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	const char	null_char = '\0';
	const char	a_char = 'a';
	int			res;

	printf("======================= test of %%c =========================\n");
	printf("==================== case1 : char 'a' =======================\n");
	printf("#1 : (warning) flag +\n");
	res = printf("%+c", a_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#2 : flag -\n");
	res = printf("%-c", a_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#3 : (warning) flag (blank)\n");
	res = printf("% c", a_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#4 : (warning) flag  #\n");
	res = printf("%#c", a_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#5 : (warning) flag 0\n");
	res = printf("%0c", a_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#6 : flag .\n");
	res = printf("%.c", a_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#7 : width(1)\n");
	res = printf("%1c", a_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#8 : width(10)\n");
	res = printf("%10c", a_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#9 : width & precision (1.)\n");
	res = printf("%1.c", a_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#10 : (warning) precision(.10)\n");
	res = printf("%.10c", a_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#11 : (warning) precision(.1)\n");
	res = printf("%.1c", a_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#12 : (warning) width & precision(10.20)\n");
	res = printf("%10.20c", a_char);
	printf("\n>> res value : %d <<\n\n\n", res);

	printf("==================== case1 : char '\\0' =======================\n");
	printf("#1 : (warning) flag +\n");
	res = printf("%+c", null_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#2 : flag -\n");
	res = printf("%-c", null_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#3 : (warning) flag (blank)\n");
	res = printf("% c", null_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#4 : (warning) flag  #\n");
	res = printf("%#c", null_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#5 : (warning) flag 0\n");
	res = printf("%0c", null_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#6 : flag .\n");
	res = printf("%.c", null_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#7 : width(1)\n");
	res = printf("%1c", null_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#8 : width(10)\n");
	res = printf("%10c", null_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#9 : width & precision (1.)\n");
	res = printf("%1.c", null_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#10 : (warning) precision(.10)\n");
	res = printf("%.10c", null_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#11 : (warning) precision(.1)\n");
	res = printf("%.1c", null_char);
	printf("\n>> res value : %d <<\n\n", res);

	printf("#12 : (warning) width & precision(10.20)\n");
	res = printf("%10.20c", null_char);
	printf("\n>> res value : %d <<\n\n\n", res);
}
