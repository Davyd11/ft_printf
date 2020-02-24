/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:46:46 by dpuente-          #+#    #+#             */
/*   Updated: 2020/02/24 12:22:11 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	spaces_char(t_flags *f)
{
	while ((((f->flag_width)-(f->var_width)) > 0) && (f->precision == 0 ||
	f->precision == 2))
	{
		write(1," ",1);
		f->flag_width--;
		f->len++;
	}
	if (f->precision == 3 && f->done == 1)
	{
		while ((((f->flag_width)-(f->var_width)) > 0) && f->precision == 3)
		{
			write(1," ",1);
			f->flag_width--;
			f->len++;
		}
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
	while (str[sum])
	{
		write(1, &str[sum], 1);
		sum++;
		f->len++;
	}
	f->done = 1;
	spaces_char(f);
}
