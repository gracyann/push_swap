/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:00:19 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/26 17:27:28 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	list_is_ordered(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_list	*find_last(t_list *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

t_list	*find_min(t_list *stack)
{
	long	min;
	t_list	*min_node;

	min = LONG_MAX;
	min_node = NULL;
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
	long	max;
	t_list	*max_node;

	max = LONG_MIN;
	max_node = NULL;
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
