/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:09:56 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/26 17:20:42 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (checking_no_digit(argc, argv) == 1 || argc == 1)
		return (0);
	init_a(argc, argv, &a);
	if (check_duplicates(a)
		|| checking_overflow(a) || !checking_if_sorted(a))
	{
		free_list(&a);
		return (0);
	}
	sort_list(&a, &b);
	free_list(&a);
	return (0);
}
