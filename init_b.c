/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:59:24 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/26 17:15:32 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*set_optimal_b(t_list *stack)
{
	while (stack)
	{
		if (stack->optimal_node == true)
			return (stack);
		stack = stack->next;
	}
	return (0);
}

void	set_match_b(t_list *a, t_list *b)
{
	t_list	*current_a;
	t_list	*match_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nb > b->nb && current_a->nb < best_match_index)
			{
				best_match_index = current_a->nb;
				match_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->match_node = find_min(a);
		else
			b->match_node = match_node;
		b = b->next;
	}
}

void	init_nodes_b(t_list *a, t_list *b)
{
	current_index(a);
	current_index(b);
	set_match_b(a, b);
}
