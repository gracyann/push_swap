/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:19:04 by arakotoa          #+#    #+#             */
/*   Updated: 2024/03/19 15:16:10 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*source;
	size_t		i;

	dst = (char *)dest;
	source = (const char *)src;
	if (dst == NULL && source == NULL)
		return (NULL);
	if (dst > source)
	{
		while (n--)
			dst[n] = source[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dst[i] = source[i];
			i++;
		}
	}
	return (dst);
}
