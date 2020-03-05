/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:46:46 by dpuente-          #+#    #+#             */
/*   Updated: 2020/03/05 13:16:37 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void uns_int(t_flags *f)
{
	long int n;
	int yes;
	
	yes = 1;
	n = va_arg(f->ap, int);
	if ((f->flag_precision == 0 && n == 0) && (f->punto > 0))
		yes = 0;
	else
	{
		if (n < 0)
			n = 4294967296 - (n * -1);
		f->var_width = ft_nbrlen(n);
		f->len += ft_nbrlen(n);
	}
	if (n < 0)
		n = 4294967296 - (n * -1);
	if (n < 0)
	{
		n = 4294967296 - (n * -1);
	}		
	if (f->fast != 1)	
	{
		if (f->punto == 0)
			f->flag_precision = f->width;
		if(n < 0)
			f->var_width--;
		spaces(f, n);
		ceros(f, n);														// CHANGE THE SIGN OF THE NUMBER IN CASE IT HAS OUTPUT THE SIGNED BEFORE
	}																				// SO THE SIGNE ISN'T DUPLICATED
	if (yes == 1)
	{
		if (n >= 10)
			ft_putnbr_fd(n / 10, 1);
		ft_putchar_fd((char)(n % 10 + 48), 1);
	}														// IF TRUE NUMBERS HAVE PRINT AND SPACES CAN BE PRINTENTED AFTER IF THERE IS A - IN THE FLAG
	f->done = 1;
	spaces(f, n);
}
//////////////////////////////////////////////////////
void	hex_putnbrbase(t_flags *f,unsigned long int n, char *base, unsigned int baselen)
{
	if (n >= baselen)
	{
		hex_putnbrbase(f, n / baselen, base, baselen);
		hex_putnbrbase(f, n % baselen, base, baselen);
	}
	else
	{
		write(1, &base[n], 1);
		f->len++;
	}	
}
////////////////////////////////////////////////////////////////////
void	hex_x(t_flags *f, char *letters)
{
	long int	n;
	int yes;
	
	yes = 1;
	n = va_arg(f->ap,long int);
	if ((f->flag_precision == 0 && n == 0) && (f->punto > 0))
		yes = 0;
	else
	{
		hex_putnbrbase_len(f, n, letters, ft_strlen(letters));
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
	}
	if (yes == 1)			
		hex_putnbrbase(f, n, letters, ft_strlen(letters));
	f->done = 1;
	spaces(f, n);
}

void	hex_pointer(t_flags *f, char *letters)
{
	unsigned long int	n;
	int yes;
	
	yes = 1;
	n = va_arg(f->ap,long int);
	if (((f->flag_precision == 0 && n == 0) && (f->punto > 0)))
	{
		yes = 0;
		f->var_width = 2;
	}
	else
	{
		hex_putnbrbase_len(f, n, letters, ft_strlen(letters));
		f->var_width += 2;
		if (n == 0)
			f->var_width = 3;
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
	}
	write(1, "0x", 2);
	f->len += 2;
	if (yes == 1)
		hex_putnbrbase(f, n, letters, ft_strlen(letters));
	f->done = 1;
	spaces(f, n);
}
