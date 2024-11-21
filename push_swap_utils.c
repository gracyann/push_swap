/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:43:07 by arakotoa          #+#    #+#             */
/*   Updated: 2024/10/11 14:13:25 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void ft_lstadd_front (t_list **lst, t_list *new)
{
    if (!lst || !new)
        return ;
    new->next = *lst;
    new->prev = NULL;
    if(*lst)
        (*lst)->prev = new;
    *lst = new;
}

int ft_atoi(char *str)
{
   int i;
   int result;
   int sign;

    i = 0;
    result = 0;
    sign = 1;

    while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if(str[i] == '+')
        i++;
    while(str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
        result = result * 10;
        result = result + (str[i] - '0');
        i++;
    }
    result = result * sign;
    return result;
}