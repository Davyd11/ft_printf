/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:46:46 by dpuente-          #+#    #+#             */
/*   Updated: 2020/02/20 13:47:30 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	int_format(t_flags *f)
{
	int n;

	n = va_arg(f->ap, int);
	f->width = ft_nbrlen(n);
	f->len +=ft_nbrlen(n); //ADD THE LENGTH OF THE NUMBER IN THE FINAL RETURN LEN OF PRINTF
	ft_putnbr_fd(n, 1);
}
