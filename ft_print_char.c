/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:46:46 by dpuente-          #+#    #+#             */
/*   Updated: 2020/02/20 13:02:50 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	single_char(t_flags *f)
{
	char *t;
	
	t = va_arg(f->ap, char *);
	write(1, &t, 1);
}

void str_format(t_flags *f)
{
	char *str;
	int sum;

	sum = 0;
	str = va_arg(f->ap, char *);
	while (str[sum] != '\0')
	{
		write(1, &str[sum], 1);
		sum++;
	}
}
