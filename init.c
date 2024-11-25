/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gracyann <gracyann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:27:47 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/24 22:27:37 by gracyann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_to_int(const char *s) 
{
	int	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void	add_node(t_list **stack, int value)
{
	t_list	*node;
	t_list	*last_node;
	
	if (!stack)
		return ;
	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->next = NULL;
	node->nb = value;
	node->optimal_node = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}
void init_a(t_list **a, char **argv)
{
    long value;
    int i;

    i = 0;
    while (argv[i])
    {
        value = str_to_int(argv[i]);
        add_node(a, (int)value);
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