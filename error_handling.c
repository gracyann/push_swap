/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:54:28 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/25 17:22:44 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int print_error(const char *message)
{
    write(2, message, 6);
    return (1);
}

int checking_no_digit(int argc, char **argv)
{
    int i;
    int j;

    i = 1; 
    while (i < argc)
    {
        j = 0;
        if (argv[i][j] == '\0')
            return print_error("Error\n");
        while (argv[i][j] != '\0')
        {
            if ((argv[i][j] == '-' || argv[i][j] == '+')
				&& !ft_isdigit(argv[i][j + 1]))
				return print_error("Error\n");
			else if ((argv[i][j] >= '0' && argv[i][j] <= '9')
				|| argv[i][j] == ' ' || argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			else
				return print_error("Error\n");
        }
        i++;
    }
    return (0);
}
int	checking_if_sorted(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		if (lst->nb > lst->next->nb)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int check_duplicates(t_list *lst)
{
    for (t_list *current = lst; current; current = current->next)
    {
        for (t_list *temp = current->next; temp; temp = temp->next)
        {
            if (current->nb == temp->nb)
                return print_error("Error\n");
        }
    }
    return (0);
}
int	checking_overflow(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->nb > INT_MAX || tmp->nb < INT_MIN)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}