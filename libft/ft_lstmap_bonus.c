/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:02:02 by dpuente-          #+#    #+#             */
/*   Updated: 2019/12/10 16:33:02 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	t_list	*aux;

	if (!f || !lst)
		return (NULL);
	aux = lst;
	if (!(new_lst = ft_lstnew(f(aux->content))))
		return (NULL);
	aux = aux->next;
	while (aux)
	{
		if (!(new_elem = ft_lstnew(f(aux->content))))
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		aux = aux->next;
	}
	return (new_lst);
}
