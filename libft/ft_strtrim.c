/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:42:16 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/06 16:44:21 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_strchr((char *)set, (int)s1[i]))
		i++;
	return (i);
}

static int	get_ending(char const *s1, char const *set)
{
	int	j;
	int	i;

	i = get_start(s1, set);
	j = ft_strlen(s1);
	while (j > i && ft_strchr((char *)set, (int)s1[j -1]))
		j--;
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*s2;

	i = get_start(s1, set);
	j = get_ending(s1, set);
	s2 = (ft_substr(s1, i, j - i));
	return (s2);
}
