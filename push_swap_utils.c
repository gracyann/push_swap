/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:43:07 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/22 17:06:13 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	stack_len(t_list *stack)
{
	int	count = 0;

	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_list	*find_last(t_list *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

bool	stack_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_list	*find_min(t_list *stack)
{
	long			min = LONG_MAX;
	t_list	*min_node = NULL;

	while (stack)
	{
		if (stack->nb < min)
		{
			min = stack->nb;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_list	*find_max(t_list *stack)
{
	long			max = LONG_MIN;
	t_list	*max_node = NULL;

	while (stack)
	{
		if (stack->nb > max)
		{
			max = stack->nb;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}