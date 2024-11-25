/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:49:17 by gracyann          #+#    #+#             */
/*   Updated: 2024/11/25 18:12:57 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	align_stacks(t_list **a, t_list **b, t_list *optimal_node)
{
	while (*b != optimal_node->match_node
		&& *a != optimal_node)
		reverse_rrr(a, b);
	current_index(*a);
	current_index(*b);
}

static void	move_optimal_to_b(t_list **a, t_list **b)
{
	t_list	*optimal_node = get_optimal_node(*a);

	if (optimal_node->above_median && optimal_node->match_node->above_median)
	{
		printf("%d ----- %s ::::: Ploup ploup\n\n", __LINE__, __FILE__);
		align_stacks(a, b, optimal_node);
		printf("%d ----- %s ::::: Ploup ploup\n\n", __LINE__, __FILE__);
	}
	else if (!optimal_node->above_median && !optimal_node->match_node->above_median)
		align_stacks(a, b, optimal_node);
	printf("%d ----- %s ::::: Ploup ploup\n\n", __LINE__, __FILE__);
	prep_for_push(a, optimal_node, 'a');
	prep_for_push(b, optimal_node->match_node, 'b');
	push_b(b, a);
}

static void	move_all_b_to_a(t_list **a, t_list **b)
{
	while (*b)
	{
		prep_for_push(a, (*b)->match_node, 'a');
		push_a(a, b);
	}
}

static void	bring_min_on_top(t_list **a)
{
	t_list	*min_node = find_min(*a);

	while ((*a)->nb != min_node->nb)
	{
		if (min_node->above_median)
			rotate_a(a);
		else
			reverse_ra(a);
	}
}

void	arrange_stacks(t_list **a, t_list **b)
{

	int	len_a;

	len_a = list_len(*a);
	if (len_a-- > 3 && !list_is_ordered(*a))
		push_b(a, b);
	if (len_a-- > 3 && !list_is_ordered(*a))
		push_b(a, b);
	while (len_a-- > 3 && !list_is_ordered(*a))
	{
		init_nodes_a(*a, *b);
		move_optimal_to_b(a, b);
		printf("%d ----- %s ::::: Ploup ploup\n\n", __LINE__, __FILE__);
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