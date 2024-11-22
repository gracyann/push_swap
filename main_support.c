/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_support.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:14:20 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/22 17:26:02 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_input(char **argv)
{
	int	av;
	int	i;

	av = 1;
	while (argv[av])
	{
		i = 0;
		while (argv[av][i] != '\0')
		{
			if ((argv[av][i] == '-' || argv[av][i] == '+')
				&& !((argv[av][i + 1] >= '0') && (argv[av][i + 1] <= '9')))
			{
				write(2, "Error\n", 6);
				return (1);
			}
			else if ((argv[av][i] >= '0' && argv[av][i] <= '9')
				|| argv[av][i] == ' '
				|| argv[av][i] == '-'
				|| argv[av][i] == '+')
			{
				i++;
			}
			else
			{
				write(2, "Error\n", 6);
				return (1);
			}
		}
		av++;
	}
	return (0);
}
void sort_list(t_list **a, t_list **b)
{
    int len = list_len(*a);

    if (len == 2)
        sa(a, false);
    else if (len == 3)
        sort_three(a);
    else
        sort_stacks(a, b);
}