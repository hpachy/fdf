/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:23:04 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/10 16:23:03 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*second;

	second = f(lst);
	first = second;
	if (!(lst))
		return (NULL);
	if (first == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		second->next = f(lst);
		if (second->next == NULL)
			return (NULL);
		second = second->next;
	}
	return (first);
}
