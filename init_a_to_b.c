/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:39:28 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/22 17:57:08 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_list *stack)
{
	int	i = 0;
	int	median = stack_len(stack) / 2;

	while (stack)
	{
		stack->i = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_list *a, t_list *b)
{
	t_list	*current_b;
	t_list	*match_node;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nb < a->nb && current_b->nb > best_match_index)
			{
				best_match_index = current_b->nb;
				match_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->optimal_node = find_max(b);
		else
			a->optimal_node = match_node;
		a = a->next;
	}
}

static void	cost_analysis_a(t_list *a, t_list *b)
{
	int	len_a = stack_len(a);
	int	len_b = stack_len(b);

	while (a)
	{
		if (a->above_median)
			a->operation_count = a->i;
		else
			a->operation_count = len_a - a->i;

		if (a->match_node->above_median)
			a->operation_count += a->match_node->i;
		else
			a->operation_count += len_b - a->match_node->i;

		a = a->next;
	}
}

void	set_cheapest(t_list *stack)
{
	t_list	*cheapest_node = NULL;
	long	cheapest_value = LONG_MAX;

	while (stack)
	{
		if (stack->operation_count < cheapest_value)
		{
			cheapest_value = stack->operation_count;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	if (cheapest_node)
		cheapest_node->optimal_node = true;
}

void	init_nodes_a(t_list *a, t_list *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}