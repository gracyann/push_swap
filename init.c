/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:27:47 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/25 14:46:37 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	how_many_digit(long n)
{
	long	c;

	c = 0;
	if (n <= 0)
		c = 1;
	while (n != 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

void	init_a(int argc, char **argv, t_list **pile_a)
{
	t_list	*temp;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			while (argv[i][j] == ' ')
				j++;
			if (argv[i][j] == '+')
				j += 1;
			temp = ft_lstnew(ft_atoi(&argv[i][j]));
			ft_lstadd_back(pile_a, temp);
			j += how_many_digit(temp->nb);
			while (argv[i][j] == 32)
				j++;
		}
		i++;
	}
}
t_list	*get_optimal_node(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->optimal_node)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_list **stack,t_list *top_node,
						char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				rotate_a(stack);
			else
				reverse_ra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rotate_b(stack);
			else
				reverse_rb(stack);
		}
	}
}