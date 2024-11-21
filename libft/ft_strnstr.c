/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:13:54 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/06 16:44:30 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	littlelen;
	size_t	biglen;

	i = 0;
	littlelen = ft_strlen(little);
	biglen = ft_strlen(big);
	if (littlelen > biglen && len < littlelen)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && len >= littlelen)
	{
		if (ft_strncmp(&big[i], little, littlelen) == 0)
			return ((char *)&big[i]);
		i++;
		len--;
	}
	return (0);
}
