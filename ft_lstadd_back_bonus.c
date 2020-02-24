/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:33:46 by dpuente-          #+#    #+#             */
/*   Updated: 2019/12/04 19:35:45 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *lisp;

	if (alst)
	{
		if (*alst == NULL)
		{
			*alst = new;
		}
		else
		{
			lisp = ft_lstlast(*alst);
			lisp->next = new;
		}
	}
}
