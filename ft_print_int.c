/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:46:46 by dpuente-          #+#    #+#             */
/*   Updated: 2020/02/27 17:51:07 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_print_int(int n, t_flags *f)											// WORKS WITH + BUT NOT WHENE YOU ADD 0 OR .
{																				// FUNCTION PLACE A + IF THE FLAG IS +
	ft_putnbr_fd(n, 1);
	f->done = 1;
}

void 	spaces(t_flags *f, int n)
{
	if (n < 0)
		f->width--;
	/*if ((f->menos == 0) && (f->done == 0) && (f->punto == 0))		//FRACMENTED WHILE FOR THE TIMEOUTS
	{
		while (f->width > f->var_width)
		{
			write(1," ",1);
			f->len++;
			f->width--;
		}
	}
	if ((f->menos == 1) && (f->done == 1) && (f->punto == 0))
	{
		while (f->width > f->var_width)
		{
			write(1," ",1);
			f->len++;
			f->width--;
		}
	}*/
	while (((f->width > f->var_width) && (((f->menos == 0) && (f->done == 0) && (f->punto == 0)))) || 
	((f->width > f->var_width) && ((f->menos == 1) && (f->done == 1) && (f->punto == 0))))
	{
		write(1," ",1);
		f->len++;
		f->width--;
	}
}
int		ceros(t_flags *f, int n)
{
	int signo;

	signo = 0;
	if ((f->punto == 1) && (f->width > f->flag_precision))
	{
		int bu;

		bu = f->width - f->flag_precision;
		while (bu)
		{
			write(1," ",1);
			f->len++;
			bu--;
		}
	}
	if((n < 0) && f->menos == 0) 											//PRECISION 1 IS ONLY WHEN THERE IS A CERO IN THE FLAG	
	{
		write(1,"-",1);
		signo = 1;
	}
	while ((f->flag_precision > f->var_width && f->menos == 0 && f->punto == 1) || 
	(f->flag_precision > f->var_width && f->menos == 1 && f->punto == 1))
	{
		ft_putnbr_fd(0, 1);
		f->len++;
		f->flag_precision--;
	}
	/*
	if((n < 0) && f->menos == 1) 											//PRECISION 1 IS ONLY WHEN THERE IS A CERO IN THE FLAG	
	{
		write(1,"-",1);
		signo = 1;
	}
	while ((((f->flag_precision)-(f->var_width)) > 0))													//ENTERS ONLY IF THER IS A CERO IN THE FLAG AND A +
	{
		ft_putnbr_fd(0, 1);
		f->flag_precision--;
		f->len++;
	}*/
	return(signo);
}
void 	int_format(t_flags *f)
{
	int n;
	
	n = va_arg(f->ap, int);														// VARIABLE NUMBER
	f->var_width = ft_nbrlen(n);												// LEN VARIABLE
	if (f->punto == 0)
		f->flag_precision = f->width;
	if(n < 0)
		f->var_width--;
	f->len += ft_nbrlen(n);														// ADD THE LENGTH OF THE NUMBER IN THE FINAL RETURN LEN OF PRINTF	
	if (f->var_width <= f->flag_precision)
		spaces(f, n);
		if ((ceros(f, n) > 0))														// CHANGE THE SIGN OF THE NUMBER IN CASE IT HAS OUTPUT THE SIGNED BEFORE
			n = n * (-1);															// SO THE SIGNE ISN'T DUPLICATED
	ft_print_int(n, f);															// IF TRUE NUMBERS HAVE PRINT AND SPACES CAN BE PRINTENTED AFTER IF THERE IS A - IN THE FLAG
	if (f->var_width <= f->flag_precision)
			spaces(f, n);
	}
