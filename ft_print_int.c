/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:46:46 by dpuente-          #+#    #+#             */
/*   Updated: 2020/02/29 16:55:29 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_print_int(long int n, t_flags *f)											// WORKS WITH + BUT NOT WHENE YOU ADD 0 OR .
{																				// FUNCTION PLACE A + IF THE FLAG IS +
	ft_putnbr_fd(n, 1);
	f->done = 1;
}

void 	spaces(t_flags *f, long int n)
{
	if (n < 0)
		f->width--;
	if ((f->menos == 0) && (f->done == 0))										//FRACMENTED WHILE FOR THE TIMEOUTS
	{
		if (((f->punto >= 1) && (f->flag_precision > f-> var_width))
		&& (f->width != 0) && (f->width > f->var_width))
		{
			f->width -= f->flag_precision;
			f->width += f->var_width;
		}
		while ((f->width > f->var_width) && (f->punto != 2))
		{
			write(1," ",1);
			f->len++;
			f->width--;
		}
	}
	if ((f->menos == 1) && (f->done == 1))
	{
		while (f->width > f->var_width)
		{
			write(1," ",1);
			f->len++;
			f->width--;
		}
		if ((n < 0) && ((ft_nbrlen(n) < 4) || ((n < 0) && ft_nbrlen(n) < 5)))
		{
			write(1," ",1);
			f->len++;
		}
			
	}
}
int		ceros(t_flags *f, long int n)
{
	int signo;

	signo = 0;
	if(n < 0) 											//PRECISION 1 IS ONLY WHEN THERE IS A CERO IN THE FLAG	
	{
		write(1,"-",1);
		signo = 1;
	}
	if((n < 0) && (f->punto == 2))
		 	f->flag_precision--;
	while ((f->flag_precision > f->var_width && f->menos == 0 && f->punto > 0) || 
	(f->flag_precision > f->var_width && f->menos == 1 && f->punto > 0))
	{
		ft_putnbr_fd(0, 1);
		f->len++;
		f->flag_precision--;
		f->width--;
	}
	return(signo);
}
void 	int_format(t_flags *f)
{
	long int n;
	int yes;
	
	yes = 1;
	n = va_arg(f->ap, int);
	if ((f->flag_precision == 0 && n == 0) && (f->punto > 0))
		yes = 0;
	else
	{
		f->var_width = ft_nbrlen(n);
		f->len += ft_nbrlen(n);
	}		
	if (f->fast != 1)	
	{
		if (f->punto == 0)
			f->flag_precision = f->width;
		if(n < 0)
			f->var_width--;
		spaces(f, n);
		if ((ceros(f, n) > 0))														// CHANGE THE SIGN OF THE NUMBER IN CASE IT HAS OUTPUT THE SIGNED BEFORE
			n = n * (-1);
	}																				// SO THE SIGNE ISN'T DUPLICATED
	if (yes == 1)
		ft_print_int(n, f);															// IF TRUE NUMBERS HAVE PRINT AND SPACES CAN BE PRINTENTED AFTER IF THERE IS A - IN THE FLAG
	f->done = 1;
	spaces(f, n);
	}
