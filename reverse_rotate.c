/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:49:18 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/25 10:17:38 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void reverse_rotate(t_list **list)
{
	int	temp;
	t_list *i;
	i = *list;
	while (i->next)
		i = i->next;
	temp = (i)->nb;
	while((i)->prev)
	{
		i->nb = (i)->prev->nb;
		i = (i)->prev;
	}
	(i)->nb = temp;
}
void reverse_ra(t_list **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void reverse_rb(t_list **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
} 

void reverse_rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}