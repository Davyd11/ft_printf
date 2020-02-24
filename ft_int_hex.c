/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:46:46 by dpuente-          #+#    #+#             */
/*   Updated: 2020/02/24 17:40:31 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void uns_int( t_flags *f)
{
	unsigned int n;
	
	n = va_arg(f->ap, unsigned int);
	f->var_width = ft_nbrlen(n);
	f->len += ft_nbrlen(n);														// ADD THE LENGTH OF THE NUMBER IN THE FINAL RETURN LEN OF PRINTF
	spaces(f, n);
	if ((ceros(f, n) > 0))														// CHANGE THE SIGN OF THE NUMBER IN CASE IT HAS OUTPUT THE SIGNED BEFORE
		n = n * (-1);															// SO THE SIGNE ISN'T DUPLICATED
	ft_print_int(n, f);															// IF TRUE NUMBERS HAVE PRINT AND SPACES CAN BE PRINTENTED AFTER IF THERE IS A - IN THE FLAG
	spaces(f, n);
}