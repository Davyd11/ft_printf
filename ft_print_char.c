/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:46:46 by dpuente-          #+#    #+#             */
/*   Updated: 2020/02/27 13:39:24 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	spaces_char(t_flags *f)
{
	while ((f->width > f->var_width && f->menos == 0 && f->done == 0) || 
	(f->width > f->var_width && f->menos == 1 && f->done == 1))
	{
		write(1," ",1);
		f->len++;
		f->width--;
	}
}
void	single_char(t_flags *f)
{
	char *t;
	
	t = va_arg(f->ap, char *);
	write(1, &t, 1);
}

void str_format(t_flags *f)
{	
	char *str;
	int sum;
	int pointer;
	int var_num;

	sum = 0;
	str = va_arg(f->ap, char *);
	f->var_width = ft_strlen(str);
	if ((f->flag_precision == 0) && (f->punto == 0))								// values are empty so print the hole str
		f->flag_precision = f->var_width;											//
	
	pointer = f->flag_precision;													// variable for ptinting string
	var_num = f->var_width;
	spaces_char(f);
	while ((pointer > 0) && (var_num > 0))
	{
		write(1, &str[sum], 1);
		pointer--;
		var_num--;
		f->len++;
		sum++;
	}
	f->done = 1;
	spaces_char(f);
}
