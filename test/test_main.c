#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	const int			num = 10;
	const unsigned int	unum = 123;
	const char			*str = "hello";
	int					i;
	int					res;

	i = 1;
	printf("=====%%s======\n");
	printf("#%d : %%s\n", i++); 
	res = ft_printf("%s", str);
	printf("\nreturn value : %d\n\n", res);

	printf("#%d : %%10s\n", i++); 
	res = ft_printf("%10s", str);
	printf("\nreturn value : %d\n\n", res);

	printf("#%d : %%10.3s\n", i++); 
	res = ft_printf("%10.3s", str);
	printf("\nreturn value : %d\n\n", res);

	printf("#%d : %%10s, s : NULL\n", i++); 
	res = ft_printf("%10s", NULL);
	printf("\nreturn value : %d\n\n", res);

	printf("=====%%d======\n");
	i = 1;
	printf("#%d : %%d, input : 10\n", i++); 
	res = ft_printf("%d", 10);
	printf("\nreturn value : %d\n", res);
	res = printf("%d", 10);
	printf("\nprintf return value : %d\n\n", res);

	printf("#%d : %%3d, input : -1\n", i++); 
	res = ft_printf("%3d", -1);
	printf("\nreturn value : %d\n", res);
	res = printf("%3d", -1);
	printf("\nprintf return value : %d\n\n", res);

	printf("#%d : %%-2d, input : -1\n", i++); 
	res = ft_printf("%-2d", -1);
	printf("\nreturn value : %d\n", res);
	res = printf("%-2d", -1);
	printf("\nprintf return value : %d\n\n", res);

	printf("#%d : %%-1d, input : 0\n", i++); 
	res = ft_printf("%-1d", 0);
	printf("\nreturn value : %d\n", res);
	res = printf("%-1d", 0);
	printf("\nprintf return value : %d\n\n", res);

	printf("#%d : %%04d, input : 9\n", i++); 
	res = ft_printf("%04d", 9);
	printf("\nreturn value : %d\n", res);
	res = printf("%04d", 9);
	printf("\nprintf return value : %d\n\n", res);

	printf("#%d : %%04d, input : -14\n", i++); 
	res = ft_printf("%04d", -14);
	printf("\nreturn value : %d\n", res);
	res = printf("%04d", -14);
	printf("\nprintf return value : %d\n\n", res);

	printf("#%d : %%046.24d, input : 0\n", i++); 
	res = ft_printf("|%046.24d|", 0);
	printf("\nreturn value : %d\n", res);
	res = printf("|%046.24d|", 0);
	printf("\nprintf return value : %d\n\n", res);
	
	printf("#%d : %%046.24d, input : 1\n", i++); 
	res = ft_printf("|%046.24d|", 1);
	printf("\nreturn value : %d\n", res);
	res = printf("|%046.24d|", 1);
	printf("\nprintf return value : %d\n\n", res);

	printf("#%d : %%046.24d, input : -11\n", i++); 
	res = ft_printf("|%046.24d|", -11);
	printf("\nreturn value : %d\n", res);
	res = printf("|%046.24d|", -11);
	printf("\nprintf return value : %d\n\n", res);

	printf("#%d : %%024.46d, input : -11\n", i++); 
	res = ft_printf("|%024.46d|", -11);
	printf("\nreturn value : %d\n", res);
	res = printf("|%024.46d|", -11);
	printf("\nprintf return value : %d\n\n", res);

	printf("#%d : %%011.2d, input : -676644014\n", i++); 
	res = ft_printf("|%011.2d|", -676644014);
	printf("\nreturn value : %d\n", res);
	res = printf("|%011.2d|", -676644014);
	printf("\nprintf return value : %d\n\n", res);

	printf("#%d : %% 014d, input : 0\n", i++); 
	res = ft_printf("|% 014d|", 0);
	printf("\nreturn value : %d\n", res);
	res = printf("|% 014d|", 0);
	printf("\nprintf return value : %d\n\n", res);

	printf("#%d : %%.0d, input : 0\n", i++); 
	res = ft_printf("|%.0d|", 0);
	printf("\nreturn value : %d\n", res);
	res = printf("|%.0d|", 0);
	printf("\nprintf return value : %d\n\n", res);

	printf("=====%%u======\n");
	printf("#%d : %%u\n", i++); 
	res = ft_printf("%u", unum);
	printf("\nreturn value : %d\n", res);
	res = printf("%u", unum);
	printf("\nreturn value : %d\n\n", res);

	printf("=====%%p======\n");
	i = 1;
	printf("#%d : %%p\n", i++); 
	res = ft_printf("%p", &unum);
	printf("\nft_printf return value : %d\n", res);
	res = printf("%p", &unum);
	printf("\nprintf return value : %d\n\n", res);

	printf("#%d : %%p\n", i++); 
	res = ft_printf("%-2p", -1);
	printf("\nft_printf return value : %d\n", res);
	res = printf("%-2p", -1);
	printf("\nprintf return value : %d\n\n", res);

	printf("#%d : %%10p, input: 0\n", i++); 
	res = ft_printf("%10p", (void *) 0);
	printf("\nft_printf return value : %d\n", res);
	res = printf("%10p", (void *) 0);
	printf("\nprintf return value : %d\n\n", res);

	printf("#%d : %%20p, input: &num\n", i++); 
	res = ft_printf("%20p", &num);
	printf("\nft_printf return value : %d\n", res);
	res = printf("%20p", &num);
	printf("\nprintf return value : %d\n\n", res);

	printf("#%d : %%20.5p, input: &num\n", i++); 
	res = ft_printf("%20.5p", &num);
	printf("\nft_printf return value : %d\n", res);
	res = printf("%20.5p", &num);
	printf("\nprintf return value : %d\n\n", res);

	printf("#%d : %%-11p %%-12p, input: INT_MIN, INT_MAX\n", i++); 
	res = ft_printf("%-11p %-12p", INT_MIN, INT_MAX);
	printf("\nft_printf return value : %d\n", res);
	res = printf("%-11p %-12p", INT_MIN, INT_MAX);
	printf("\nprintf return value : %d\n\n", res);

	printf("=====%%x======\n");
	i = 1;
	printf("#%d : %%#x, input: 0\n", i++); 
	res = ft_printf("|%#x|", 0);
	printf("\nft_printf return value : %d\n", res);
	res = printf("|%#x|", 0);
	printf("\nprintf return value : %d\n\n", res);
	
	printf("#%d : %%#28.4x, input: -1419627386\n", i++); 
	res = ft_printf("|%#28.4x|", -1419627386);
	printf("\nft_printf return value : %d\n", res);
	res = printf("|%#28.4x|", -1419627386);
	printf("\nprintf return value : %d\n\n", res);

	printf("#%d : %%#-28.4x, input: -1419627386\n", i++); 
	res = ft_printf("|%#-28.4x|", -1419627386);
	printf("\nft_printf return value : %d\n", res);
	res = printf("|%#-28.4x|", -1419627386);
	printf("\nprintf return value : %d\n\n", res);

	printf("#%d : %%42%%#54.39x42, input: 0\n", i++); 
	res = ft_printf("|42%#54.39x42|", 0);
	printf("\nft_printf return value : %d\n", res);
	res = printf("|42%#54.39x42|", 0);
	printf("\nprintf return value : %d\n\n", res);

	printf("=====%%======\n");
	i = 1;
	printf("#%d : %%-05%%\n", i++); 
	res = ft_printf("|%-05%|");
	printf("\nft_printf return value : %d\n", res);
	res = printf("|%-05%|");
	printf("\nprintf return value : %d\n\n", res);
}