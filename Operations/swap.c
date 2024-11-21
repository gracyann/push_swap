/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:18:46 by arakotoa          #+#    #+#             */
/*   Updated: 2024/08/14 16:47:56 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list *list)
{
	int temp;
	if (!list || !list->next)
		return ;
	temp = list->nb;
	list->nb = list->next->nb;
	list->next->nb = temp;
}

void swap_a(t_list *pa)
{
	swap(pa);
	write(1, "sa\n", 3);
}

void swap_b(t_list *pb)
{
	swap(pb);
	write(1, "sb\n", 3);
}

void swap_ss(t_list *pa, t_list *pb)
{
	swap(pa);
	swap(pb);
	write(1, "ss\n", 3);
}
