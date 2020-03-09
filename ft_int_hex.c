/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:46:46 by dpuente-          #+#    #+#             */
/*   Updated: 2020/03/09 16:18:14 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		uns_utils(t_flags *f, long int n, int yes)
{
	if (f->fast != 1)
	{
		if (f->punto == 0)
			f->flag_precision = f->width;
		if (n < 0)
			f->var_width--;
		spaces(f, n);
		ceros(f, n);
	}
	if (yes == 1)
	{
		if (n >= 10)
			ft_putnbr_fd(n / 10, 1);
		ft_putchar_fd((char)(n % 10 + 48), 1);
	}
	f->done = 1;
	spaces(f, n);
}

void		uns_int(t_flags *f)
{
	long	int	n;
	int			yes;

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
	uns_utils(f, n, yes);
}

void		hex_putnbrbase(t_flags *f, unsigned long int n,
char *base, unsigned int baselen)
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

void		hex_x(t_flags *f, char *letters)
{
	long int	n;
	int			yes;

	yes = 1;
	n = va_arg(f->ap, unsigned int);
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
		if (n < 0)
			f->var_width--;
		spaces(f, n);
		if ((ceros(f, n) > 0))
			n = n * (-1);
	}
	if (yes == 1)
		hex_putnbrbase(f, n, letters, ft_strlen(letters));
	f->done = 1;
	spaces(f, n);
}

void		hex_pointer(t_flags *f, char *letters)
{
	unsigned long			n;
	int						yes;

	yes = 1;
	n = va_arg(f->ap, unsigned long);
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
	if (f->flag_precision > f->var_width && f->punto == 1)
		f->var_width -= 2;
	hex_pointer_utils(f, letters, n, yes);
}
