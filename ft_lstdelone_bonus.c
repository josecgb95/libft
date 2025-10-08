/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:28:58 by jose-car          #+#    #+#             */
/*   Updated: 2025/10/08 11:55:51 by jose-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*It takes an 'lst' node as a parameter and frees the contents'
memory using the 'del' function given as a parameter,
in addition to freeing the node. The memory in 'next' should not be freed.*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
