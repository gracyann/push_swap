/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:51:16 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/06 16:45:08 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*source;
	size_t		i;

	dst = dest;
	source = src;
	i = 0;
	if (dst == NULL && source == NULL)
		return (NULL);
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dst);
}
