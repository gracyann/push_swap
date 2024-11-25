/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gracyann <gracyann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:49:17 by gracyann          #+#    #+#             */
/*   Updated: 2024/11/24 21:39:05 by gracyann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	align_stacks(t_list **a, t_list **b, t_list *optimal_node, int direction)
{
	while (*a != optimal_node || *b != optimal_node->match_node)
	{
		if (direction == 1)
			reverse_rotate(a, b, false);
		else
			reverse_rrr(a, b, false);
	}
}

static void	move_optimal_to_b(t_list **a, t_list **b)
{
	t_list	*optimal_node = get_optimal_node(*a);

	if (optimal_node->above_median && optimal_node->match_node->above_median)
		align_stacks(a, b, optimal_node, 1);
	else if (!optimal_node->above_median && !optimal_node->match_node->above_median)
		align_stacks(a, b, optimal_node, -1);

	prep_for_push(a, optimal_node, 'a');
	prep_for_push(b, optimal_node->match_node, 'b');
	push_b(b, a, false);
}

static void	move_all_b_to_a(t_list **a, t_list **b)
{
	while (*b)
	{
		prep_for_push(a, (*b)->match_node, 'a');
		push_a(a, b, false);
	}
}

static void	bring_min_to_top(t_list **a)
{
	t_list	*min_node = find_min(*a);

	while ((*a)->nb != min_node->nb)
	{
		if (min_node->above_median)
			rotate_a(a, false);
		else
			rra(a, false);
	}
}

void	arrange_stacks(t_list **a, t_list **b)
{

	int	len_a;

	len_a = list_len(*a);
	if (len_a-- > 3 && !list_is_ordered(*a)) 
		push_b(b, a, false);
	if (len_a-- > 3 && !list_is_ordered(*a))
		push_b(b, a, false);
	while (len_a-- > 3 && !list_is_ordered(*a))
	{
		init_nodes_a(*a, *b); 
		move_optimal_to_b(a, b); 
	}
	arrange_three(a);
	while (*b) 
	{
		init_nodes_b(*a, *b); 
		move_all_b_to_a(a, b);
	}
	current_index(*a); 
	bring_min_on_top(a);
}