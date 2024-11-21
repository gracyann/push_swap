/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:14:48 by arakotoa          #+#    #+#             */
/*   Updated: 2024/10/11 15:48:55 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int if_not_digit (char **av)
{
    int i;
    int j;
    i = 1;
    while(av[i])
    {
        j = 0;
        while(av[i][j])
        {
            if((av[i][j] < 48 || av[i][j] > 57) && (av[i][j] != '-' && av[i][j] != '+'))
            {
                write(2, "Error\n", 6);
                return -1;
            }
            j++;
        }
        i++;
    }
    return 0;
}

int if_same_value (t_list *list)
{
    t_list *temp;
    while(list != NULL)
    {
        temp = list->next;
        while(temp != NULL)
        {
            if (list->nb == temp->nb)
            {
                write(2, "Error/n", 6);
                return -1;
            }
            temp = temp->next;
        }
        list = list->next;
    }
    return 0;
}

int nb_limits (char **av)
{
    int i;
    while(av[i])
    {
        if(ft_atoi(av[i] > 2147483647) || ft_atoi(av[i]) < -2147483648)
        {
            write(2, "Error/n", 6);
            return 1;
        }
        i++;
    }
    return 0;
}