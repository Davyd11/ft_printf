/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:31:54 by dpuente-          #+#    #+#             */
/*   Updated: 2020/03/03 15:07:30 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	//int i;
	//int p;
	//float f;
	//double d;
	char *ch;
	char *pp;
	char *jj;
	//char c;

	//i = -123;
	//p = 11;
	//f = 3209.1417;
	//d = 123.456789;
	//c = 'D';
	pp = "uweyw2832983429wieu";
	jj = "djfhkslskjf";
	ch = "Estamos genial tio";
	/*char *s = "Mundo";
	int i = 56;
	unsigned int x = 0;*/

		//printf("Hola <%10.5s><%7.4i><%x>\n", s, i, x);						int i = -62; unsigned int j = (unsigned int)i;
		//ft_printf("Hola <%10.5s><%7.4i><%x>\n", s, i, x);
		printf("\n----------------------");
		printf("\nOriginal: \n");
		
		/////////////////////////////////////////////
		   printf("--%d", printf("%-3p", pp));//////
		/////////////////////////////////////////////
		
		printf("\n\n");
		printf("FT_COPY: \n");
		
		//////////////////////////////////////////////
		printf("--%d",ft_printf("%-3p", pp));//////
		//////////////////////////////////////////////
		
		printf("\n----------------------\n\n");
}
