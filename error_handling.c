/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gracyann <gracyann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:54:28 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/24 19:26:06 by gracyann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *str)
{
	int	i;
	i = 0;
	if (!(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
		return (1);
	if ((str[i] == '+' || str[i] == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	i++;
	while (str[i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	return (0);
}

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

void free_errors(t_list **a)
{
    free_list(a);
    write(2, "Error\n", 6);
    exit(EXIT_FAILURE);
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