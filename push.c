/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:48:49 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/25 09:30:25 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_a(t_list **a, t_list **b)
{
    t_list *temp;
    if(!b && !*b)
        return ;
    temp = *b;
    *b = (*b)->next;
    if(*b)
        (*b)->prev=NULL;
    temp->prev=NULL;
    temp->next=NULL;
    ft_lstadd_front(a, temp);
    write(1, "pa\n", 3); 
}

void push_b(t_list **a, t_list **b)
{
    t_list *temp;
    if(!a && !*a)
        return ;
    temp = *a;
    *a = (*a)->next;
    if(*a)
        (*a)->prev=NULL;
    temp->prev=NULL;
    temp->next=NULL;
    ft_lstadd_front(b, temp);
    write(1, "pb\n", 3);
}
