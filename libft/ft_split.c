/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:54:37 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/25 10:45:26 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	if (!s[0])
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			nb++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (nb);
}

static int	lenght_string(const char *s, char c)
{
	int	lenght;

	lenght = 0;
	while (s[lenght] && s[lenght] != c)
		lenght++;
	return (lenght);
}

static char	**ft_free(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (NULL);
}

static char	**ft_function(char **tab, char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		if (s[j] != '\0')
		{
			tab[i] = ft_substr(s, j, lenght_string(&s[j], c));
			if (!tab[i])
				return (ft_free(tab, i));
			i++;
			j = j + lenght_string(&s[j], c);
		}
	}
	tab[i] = 0;
	return (tab);
}

char	**ft_split(char *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (0);
	tab = ft_function(tab, s, c);
	return (tab);
}
