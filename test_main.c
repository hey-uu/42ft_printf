#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	const int			num = 0;
	const unsigned int	unum = 123;
	const char			*str = "hello";
	int					i;
	int					res;

	i = 1;
	printf("=====%%s======\n");
	printf("%d : %%s\n", i++); 
	res = ft_printf("%s", str);
	printf("\nreturn value : %d\n\n", res);

	printf("%d : %%10s\n", i++); 
	res = ft_printf("%10s", str);
	printf("\nreturn value : %d\n\n", res);

	printf("%d : %%10.3s\n", i++); 
	res = ft_printf("%10.3s", str);
	printf("\nreturn value : %d\n\n", res);

	printf("%d : %%10s, s : NULL\n", i++); 
	res = ft_printf("%10s", NULL);
	printf("\nreturn value : %d\n\n", res);

	printf("=====%%d======\n");
	printf("%d : %%d\n", i++); 
	res = ft_printf("%d", num);
	printf("\nreturn value : %d\n\n", res);

	printf("=====%%u======\n");
	printf("%d : %%u\n", i++); 
	res = ft_printf("%u", unum);
	printf("\nreturn value : %d\n\n", res);

	printf("=====%%p======\n");
	printf("%d : %%p\n", i++); 
	res = ft_printf("%p", &unum);
	printf("\nft_printf return value : %d\n\n", res);
	res = printf("%p", &unum);
	printf("\nprintf return value : %d\n\n", res);

	printf("%d : %%p\n", i++); 
	res = ft_printf("%-2p", -1);
	printf("\nft_printf return value : %d\n\n", res);
	res = printf("%-2p", -1);
	printf("\nprintf return value : %d\n\n", res);
}