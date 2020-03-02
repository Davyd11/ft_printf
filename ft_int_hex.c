/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:46:46 by dpuente-          #+#    #+#             */
/*   Updated: 2020/03/02 23:07:09 by davyd11          ###   ########.fr       */
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
void	hex_putnbrbase(t_flags *f, int n, char *base, int baselen)
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

void	hex_printer(t_flags *f, unsigned int n, char *base)
{
	if (f->flag_precision && !f->precision && !n)
	{
		if (f->width)
		{
			write(1, " ", 1);
			f->len++;
		}
	}
	else
		hex_putnbrbase(f, n, base, ft_strlen(base));	
}
//////////////////////////////////////////////////////
void	hex_x(t_flags *f, char *letters)
{
	int		n;

	n = va_arg(f->ap, int);
	f->var_width = hex_nbrlen(n, letters);
	if (f->fast != 1)	
	{
		spaces(f, n);
	}				
	hex_printer(f, n, letters);
	f->done = 1;
	spaces(f, n);
}

void	point_add(t_flags *f)// NOT WORKING FOR NOW
{
	int n;
	int* a;
	
	n = va_arg(f->ap, int);
	a = &n;
	printf("Entra");
	write(1,&a,30);	
}