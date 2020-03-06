/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:31:54 by dpuente-          #+#    #+#             */
/*   Updated: 2020/03/06 18:46:41 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	//int i;
	//int p;
	//float f;
	//double d;
	char *ch;
	int ret;
	//char *pp;
	//char *jj;
	//char c;

	//i = -123;
//	p = 1234;
	//f = 3209.1417;
	//d = 123.456789;
	//c = 'D';
	//pp = "1234";
	//jj = "djfhkslskjf";
	ch = "Estamos genial tio";
	/*char *s = "Mundo";
	int i = 56;
	unsigned int x = 0;*/

		printf("\n----------------------");
		printf("\nOriginal: \n");
		
		/////////////////////////////////////////////
		//printf(":%d",printf("%--.4u et %#O%#012O%1lc\n", -12, 0, 0, 95));
		//printf(":%d",printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));
		//printf(":%d",printf("test%-8p %---32p %#5.3x%#024X", &ret, &ret, 0x25, 0));
		//printf(":%d",printf("test %-7C %007d%-10.2ls!!", 0xd777, 0x45, L"〻"));
		//printf(":%d",printf("test %-7C %007d%-10.2ls!!", 0xd777, 0x45, L"〻"));
		//printf(":%d",printf("%2.9p", 1234));
		printf(":%d",printf("%p%p%p%p%p%p%p%p%p%p%p",12,12,12,12,12,12,12,12,12,12,12));
		/////////////////////////////////////////////
		
		printf("\n\n");
		printf("FT_COPY: \n");
		
		//////////////////////////////////////////////
		printf(":%d",ft_printf("%p%p%p%p%p%p%p%p%p%p%p",12,12,12,12,12,12,12,12,12,12,12));
		//printf(":%d",ft_printf("%2.9p", 1234));//////"%.*s", 42 //IMPORTANT
		//ft_printf("Hello, World!");
		//////////////////////////////////////////////
		//printf("--%d", printf("%s%d%c%i%s%p%s%s%s%s\n", "12", 12, 'h', 12, ch, ch, "12", "12", "12", "12"));
		printf("\n----------------------\n\n");
		//printf("--%d", ft_printf("%s%d%c%i%s%p%s%s%s%s\n", "12", 12, 'h', 12, ch, ch, "12", "12", "12", "12"));


		//system("leaks a.out");
}
