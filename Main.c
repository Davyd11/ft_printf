/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:31:54 by dpuente-          #+#    #+#             */
/*   Updated: 2020/02/24 22:16:26 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int i;
	//int p;
	//float f;
	//double d;
	char *ch;
	//char c;

	i = -123;
	//p = 11;
	//f = 3209.1417;
	//d = 123.456789;
	//c = 'D';
	ch = "Estamos genial tio";
	/*char *s = "Mundo";
	int i = 56;
	unsigned int x = 0;*/

		//printf("Hola <%10.5s><%7.4i><%x>\n", s, i, x);						int i = -62; unsigned int j = (unsigned int)i;
		//ft_printf("Hola <%10.5s><%7.4i><%x>\n", s, i, x);
		printf("\n----------------------");
		printf("\nOriginal: \n");
		
		/////////////////////////////////////////////
		   printf("%d",(printf("Hola que tal estamos:%-.20u||------->", i)));//////-0.*
		   printf("\n\n");
		   printf("%d",(printf("Hola que tal estamos:%20s||------->", ch)));//////-0.*
		/////////////////////////////////////////////
		
		printf("\n\n");
		printf("FT_COPY: \n");
		
		//////////////////////////////////////////////
		printf("%d",(ft_printf("Hola que tal estamos:%-.20u||------->", i)));//////-0.*
		printf("\n\n");
		printf("%d",(printf("Hola que tal estamos:%20s||------->", ch)));//////-0.*
		//////////////////////////////////////////////
		
		printf("\n----------------------\n\n");
}