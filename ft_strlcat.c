/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:04:58 by dpuente-          #+#    #+#             */
/*   Updated: 2019/12/12 15:16:35 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t rsl;

	i = ft_strlen(dest);
	rsl = ft_strlen(src);
	j = 0;
	if (size == 0)
		return (rsl);
	if (size < i)
	{
		rsl += size;
	}
	else
	{
		rsl += i;
		while (src[j] != '\0' && i < size - 1 && dest != src)
		{
			dest[i] = src[j];
			j++;
			i++;
		}
		dest[i] = '\0';
	}
	return (rsl);
}
