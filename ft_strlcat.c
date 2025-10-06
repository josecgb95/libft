/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 09:31:27 by jose-car          #+#    #+#             */
/*   Updated: 2025/10/02 12:19:54 by jose-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	l_src;
	size_t	l_dest;
	size_t	i;

	l_src = 0;
	l_dest = 0;
	while (src[l_src])
		l_src++;
	while (dest[l_dest] && l_dest < size)
		l_dest++;
	if (l_dest == size)
		return (l_src + size);
	i = 0;
	while ((l_dest + i < size - 1) && (src[i]))
	{
		dest[l_dest + i] = src[i];
		i++;
	}
	dest[l_dest + i] = '\0';
	return (l_dest + l_src);
}
