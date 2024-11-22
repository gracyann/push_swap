/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:21:50 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/22 16:09:16 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "./libft/libft.h"

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

t_list	*get_optimal_node(t_list *stack);

//int ft_atoi(char *str);

char **split(char *str, char delimiter);

void sort_list(t_list **a, t_list **b);
void	init_a(t_list **a, char **argv);
void ft_lstadd_front (t_list **lst, t_list *new);
void	prep_for_push(t_list **stack,t_list *top_node,
						char stack_name);

#endif
