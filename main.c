/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:09:56 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/22 17:17:53 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *a;
    t_list *b;

    a = NULL;
    b = NULL;
    if (argc <= 1)
        return (0);
    if (validate_input(argv))
		return (1);
    else if (argc == 2 && !argv[1][0] != '\0')
        argv = split(argv[1], ' ');
    init_a(&a, argv + 1);
    if (!list_is_ordered(a))
        sort_list(&a, &b);
    free_list(&a);
    return (0);
}