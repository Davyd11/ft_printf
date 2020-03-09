/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:46:46 by dpuente-          #+#    #+#             */
/*   Updated: 2020/03/09 16:34:14 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_flags *f)
{
	if ((f->flag_precision == 0) && (f->punto == 0))
		f->flag_precision = f->var_width;
	if (f->punto == 2)
		f->flag_precision = f->var_width;
	if (f->flag_precision < 0)
		f->flag_precision = f->var_width;
	if (f->flag_precision < f->var_width)
		f->var_width = f->flag_precision;
}

void	spaces_char(t_flags *f)
{
	while ((f->width > f->var_width && f->menos == 0 && f->done == 0) ||
	(f->width > f->var_width && f->menos == 1 && f->done == 1))
	{
		write(1, " ", 1);
		f->len++;
		f->width--;
	}
}

void	single_char(t_flags *f)
{
	char *t;

	t = (char *)va_arg(f->ap, char *);
	f->width--;
	if (f->fast != 1)
		spaces_char(f);
	write(1, &t, 1);
	f->len++;
	f->done = 1;
	spaces_char(f);
}

void	str_format(t_flags *f)
{
	char	*str;
	int		sum;
	int		pointer;
	int		var_num;

	sum = 0;
	str = (char *)va_arg(f->ap, char *);
	if (!str)
		str = "(null)";
	if (f->flag_precision == 0 && f->punto == 1)
		str = "";
	else
		f->var_width = ft_strlen(str);
	print_char(f);
	pointer = f->flag_precision;
	var_num = f->var_width;
	if (f->fast != 1)
	{
		if (f->punto != 2)
			spaces_char(f);
	///////////////////////////////////////
		if (f->punto == 2 && f->width > 0)
		{
			f->flag_precision = f->width;
			ceros(f, f->var_width);
		}
	}
	////////////////////////////////////////
	while ((pointer && var_num))
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
