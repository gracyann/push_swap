/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gracyann <gracyann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:00:19 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/24 17:57:01 by gracyann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void ft_lstadd_front (t_list **lst, t_list *new)
{
    if (!lst || !new)
        return ;
    new->next = *lst;
    new->prev = NULL;
    if(*lst)
        (*lst)->prev = new;
    *lst = new;
}

t_list	*find_last(t_list *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
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