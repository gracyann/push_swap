/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:21:50 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/21 15:57:29 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct	s_list
{
	int		nb;
	int		i;
	int		operation_count;
	bool	optimal_node;
	bool	above_median;
	struct s_list *match_node;
	struct s_list *next;
	struct s_list *prev;
}				t_list;

int if_not_digit(char **av);
int ft_atoi(char *str);

void ft_lstadd_front (t_list **lst, t_list *new);

#endif
