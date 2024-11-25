/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gracyann <gracyann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:09:56 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/24 17:56:09 by gracyann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	list_is_ordered(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int main(int argc, char **argv)
{
    t_list *a;
    t_list *b;
    long value;
    int i;

    a = NULL;
    b = NULL;
    if (argc <= 1)
        return (0);
    i = 1;
    while (i < argc)
    {
        if (error_syntax(argv[i]))
            free_errors(&a);
        value = str_to_int(argv[i]);
        if (value > INT_MAX || value < INT_MIN)
            free_errors(&a);
        i++;
    }
    if (argc == 2 && argv[1][0] != '\0')
        argv = split(argv[1], ' ');
    init_a(&a, argv + 1);
    if (!list_is_ordered(a))
        sort_list(&a, &b);
    free_list(&a);
    return (0);
}