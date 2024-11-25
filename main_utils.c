/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:54:39 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/25 14:55:05 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list **stack)
{
	t_list	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	list_len(t_list *stack)
{
	int	count = 0;

	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);  
}

void sort_list(t_list **a, t_list **b)
{
    int len = list_len(*a);

    if (len == 2)
        swap_a(a);
    else if (len == 3)
        arrange_three(a);
    else
        arrange_stacks(a, b);
}