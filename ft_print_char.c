/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:46:46 by dpuente-          #+#    #+#             */
/*   Updated: 2020/02/26 22:38:22 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	spaces_char(t_flags *f)
{
	while (((f->width > f->flag_precision) && ((f->menos == 0) && (f->done != 1))) || 
	((f->width > f->flag_precision) && ((f->menos == 1) && (f->done = 1))))
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
	
	sum = 0;
	str = va_arg(f->ap, char *);
	f->var_width = ft_strlen(str);
	spaces_char(f);
	while ((f->flag_precision > 0) && (f->var_width > 0))
	{
		write(1, &str[sum], 1);
		f->flag_precision--;
		f->var_width--;
		f->len++;
		sum++;
	}
	f->done = 1;
	spaces_char(f);
}
