/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:49:19 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/26 17:24:56 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_min_on_top(t_list **a)
{
	t_list	*min_node;
	long	min;

	min_node = find_min(*a);
	min = min_node->nb;
	while ((*a)->nb != min)
	{
		if (min_node->above_median)
			rotate_a(a);
		else
			reverse_ra(a);
	}
}

void	rotate(t_list **list)
{
	t_list	*last_node;

	if (!*list || !(*list)->next)
		return ;
	last_node = find_last(*list);
	last_node->next = *list;
	*list = (*list)->next;
	(*list)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	rotate_a(t_list **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rotate_rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
