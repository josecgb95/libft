/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:15:11 by jose-car          #+#    #+#             */
/*   Updated: 2025/10/07 14:41:19 by jose-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Deletes and frees the given 'lst' node and all consecutive nodes
within that node, using the 'del' function and free(3).
At the end, the list pointer must be NULL.*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_1;
	t_list	*temp_2;

	if (!lst || !(*lst) || !del)
		return ;
	temp_2 = (*lst);
	temp_1 = temp_2;
	while (temp_1 != NULL)
	{
		temp_1 = temp_1->next;
		ft_lstdelone(temp_2, del);
		temp_2 = temp_1;
	}
	*lst = NULL;
}
