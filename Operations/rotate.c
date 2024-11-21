/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:49:19 by arakotoa          #+#    #+#             */
/*   Updated: 2024/08/19 09:44:56 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void rotate(t_list *list)
{
	int temp;

	temp = list->nb;
	while(list->next != NULL)
	{
		list->nb = list->next->nb;
		list = list->next;
	}
	list->nb = temp;
}

void rotate_a(t_list *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void rotate_b(t_list *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void rotate_rr(t_list *a, t_list *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
