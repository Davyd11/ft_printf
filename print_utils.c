/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:36:05 by dpuente-          #+#    #+#             */
/*   Updated: 2020/03/06 18:41:08 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spaces_after(t_flags *f, long int n)
{
	if ((f->menos == 1) && (f->done == 1))
	{
		while (f->width > f->var_width)
		{
			write(1, " ", 1);
			f->len++;
			f->width--;
		}
		if ((n < 0) && ((ft_nbrlen(n) < 4) || ((n < 0) && ft_nbrlen(n) < 5)))
		{
			write(1, " ", 1);
			f->len++;
		}
	}
}

void	format_utils(t_flags *f, long int n, int yes)
{
	if (f->fast != 1)
	{
		if (f->punto == 0)
			f->flag_precision = f->width;
		if (n < 0)
			f->var_width--;
		spaces(f, n);
		if ((ceros(f, n) > 0))
			n = n * (-1);
	}
	if (yes == 1)
		ft_print_int(n, f);
	f->done = 1;
	spaces(f, n);
}

void	hex_pointer_utils(t_flags *f, char *letters,
unsigned long int n, int yes)
{
	if (f->fast != 1)
	{
		if (f->punto == 0)
			f->flag_precision = f->width;
		if (n < 0)
			f->var_width--;
		spaces(f, n);
		if ((ceros(f, n) > 0))
			n = n * (-1);
	}
	write(1, "0x", 2);
	f->len += 2;
	if (yes == 1)
		hex_putnbrbase(f, n, letters, ft_strlen(letters));
	f->done = 1;
	spaces(f, n);
}
