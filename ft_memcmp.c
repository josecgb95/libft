/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 09:16:49 by jose-car          #+#    #+#             */
/*   Updated: 2025/10/01 10:52:10 by jose-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	i = 0;
	p_s1 = (unsigned char *) s1;
	p_s2 = (unsigned char *) s2;
	while (i < n)
	{
		if (p_s1[i] != p_s2[i])
		{
			return (p_s1[i] - p_s2[i]);
		}
		i++;
	}
	return (0);
}
