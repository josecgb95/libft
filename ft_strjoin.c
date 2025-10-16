/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:26:02 by jose-car          #+#    #+#             */
/*   Updated: 2025/10/03 11:29:20 by jose-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// concatenate str1 and str2
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len;

	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	ft_strcpy(new_str, (char *)s1);
	len = ft_strlen(new_str);
	ft_strcpy(&new_str[len], (char *)s2);
	new_str[ft_strlen(new_str)] = '\0';
	return (new_str);
}
