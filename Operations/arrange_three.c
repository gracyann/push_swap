/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gracyann <gracyann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:21:07 by gracyann          #+#    #+#             */
/*   Updated: 2024/11/24 18:03:47 by gracyann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arrange_three(t_list **a)
{
	t_list	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		rotate_a(a, false);
	else if ((*a)->next == biggest_node)
		reverse_ra(a, false);
	if ((*a)->nb > (*a)->next->nb)
		swap_a(a, false);
}