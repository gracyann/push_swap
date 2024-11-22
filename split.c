/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:56:17 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/22 17:18:07 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static int count_delimited_words(char *str, char delimiter)
{
    int count = 0;
    bool in_word = false;

    while (*str)
    {
        if (*str == delimiter)
            str++;
        else
        {
            if (!in_word)
            {
                count++;
                in_word = true;
            }
            str++;
        }
    }
    return count;
}

static char *get_word(char *str, char delimiter)
{
    static int index = 0;
    char *word;
    int length = 0;
    int i = 0;

    while (str[index] == delimiter)
        index++;
    
    while (str[index + length] != delimiter && str[index + length])
        length++;
    
    word = malloc(length + 1);
    if (!word)
        return NULL;

    while (str[index] != delimiter && str[index])
        word[i++] = str[index++];
    word[i] = '\0';

    return word;
}

char **split(char *str, char delimiter)
{
    int word_count = count_delimited_words(str, delimiter);
    char **result = malloc((word_count + 1) * sizeof(char *));
    int i = 0;

    if (!result)
        return NULL;

    while (i < word_count)
    {
        result[i++] = get_word(str, delimiter);
    }
    result[i] = NULL;

    return result;
}