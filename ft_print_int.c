/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:46:46 by dpuente-          #+#    #+#             */
/*   Updated: 2020/02/20 14:39:07 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	spaces(t_flags *f)
{
	while ((((f->flag_width)-(f->var_width)) > 0) && f->precision == 0)
	{
		write(1," ",1);
		f->flag_width--;
		f->len++;
	}
}

int		ceros(t_flags *f, int n)
{
	int signo;

	signo = 0;
	if((n < 0) && f->precision == 1)
	{
		write(1,"-",1);
		signo = 1;
	}
	while ((((f->flag_width)-(f->var_width)) > 0) && f->precision == 1)
	{
		ft_putnbr_fd(0, 1);
		f->flag_width--;
		f->len++;
	}
	return (signo);
}

void 	int_format(t_flags *f)
{
	int n;

	n = va_arg(f->ap, int);
	f->var_width = ft_nbrlen(n);
	f->len +=ft_nbrlen(n); //ADD THE LENGTH OF THE NUMBER IN THE FINAL RETURN LEN OF PRINTF
	if ((ceros(f, n) > 0))
		n = n * (-1);
	spaces(f);
	ft_putnbr_fd(n, 1);
}
