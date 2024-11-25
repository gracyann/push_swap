/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gracyann <gracyann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:49:18 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/24 22:32:39 by gracyann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void reverse_rotate(t_list **list)
{
	int	temp;
	t_list **i;
	i = list;
	while((*i)->next)
		i = (*i)->next;
	temp = (*i)->nb;
	while((*i)->prev)
	{
		i = (*i)->prev->nb;
		i = (*i)->prev;
	}
	(*i)->nb = temp;
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