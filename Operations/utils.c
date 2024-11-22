/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:00:19 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/22 17:00:54 by arakotoa         ###   ########.fr       */
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