/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:31:54 by dpuente-          #+#    #+#             */
/*   Updated: 2020/03/05 14:09:29 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	//int i;
	//int p;
	//float f;
	//double d;
	//char *ch;
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
	//ch = "Estamos genial tio";
	/*char *s = "Mundo";
	int i = 56;
	unsigned int x = 0;*/

		printf("\n----------------------");
		printf("\nOriginal: \n");
		
		/////////////////////////////////////////////
		printf("--%d",printf("hello, World!"));
		/////////////////////////////////////////////
		
		printf("\n\n");
		printf("FT_COPY: \n");
		
		//////////////////////////////////////////////
		printf("--%d",ft_printf("hello, World!"));//////"%.*s", 42 //IMPORTANT
		//ft_printf("Hello, World!");
		//////////////////////////////////////////////
		
		printf("\n----------------------\n\n");
}
