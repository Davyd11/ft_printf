/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_hex_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 22:15:28 by davyd11           #+#    #+#             */
/*   Updated: 2020/03/05 17:22:07 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		hex_nbrlen(int n, char *base)
{
	int baselen;
	int len;

	len = 0;
	baselen = ft_strlen(base);
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= baselen;
		len++;
	}
	return (len);
}
