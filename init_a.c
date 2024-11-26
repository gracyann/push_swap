/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:39:28 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/26 17:42:51 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_list *stack)
{
	int	i;
	int	median;

	i = 0;
	median = list_len(stack) / 2;
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

static void	set_match_a(t_list *a, t_list *b)
{
	t_list	*current_b;
	t_list	*match_node;
	long	best_match_index;

	match_node = NULL;
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
			a->match_node = find_max(b);
		else
			a->match_node = match_node;
		a = a->next;
	}
}

void	calculate_stack_operation(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = list_len(a);
	len_b = list_len(b);
	while (a)
	{
		a->operation_count = a->i;
		if (!(a->above_median))
		{
			a->operation_count = len_a - (a->i);
		}
		if (a->match_node->above_median)
			a->operation_count += a->match_node->i;
		else
			a->operation_count += len_b - (a->match_node->i);
		a = a->next;
	}
}

void	set_optimal(t_list *stack)
{
	t_list	*opti_node;
	long	optimal_value;

	opti_node = NULL;
	optimal_value = LONG_MAX;
	while (stack)
	{
		if (stack->operation_count < optimal_value)
		{
			optimal_value = stack->operation_count;
			opti_node = stack;
		}
		stack = stack->next;
	}
	opti_node->optimal_node = true;
}

void	init_nodes_a(t_list *a, t_list *b)
{
	current_index(a);
	current_index(b);
	set_match_a(a, b);
	calculate_stack_operation(a, b);
	set_optimal(a);
}
