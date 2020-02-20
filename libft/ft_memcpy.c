/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:23:19 by davyd11           #+#    #+#             */
/*   Updated: 2019/12/02 16:16:43 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	if (!len || dest == src)
		return (dest);
	while (len--)
		*str1++ = *str2++;
	return (dest);
}
