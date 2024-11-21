/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:09:56 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/21 17:37:26 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *a;
    t_list *b;
    int len;

    a = NULL;
    b = NULL;
    if (argc <= 1)
        return (0);
    else if (argc == 2 && !argv[1][0] != '\0')
        argv = split(argv[1], ' ');
    init_a(&a, argv + 1);
    if (!list_is_ordered(a))
        sort_list(&a, &b);
    free_list(&a);
    return (0);
}