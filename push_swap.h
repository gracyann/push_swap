/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gracyann <gracyann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:21:50 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/24 22:38:21 by gracyann         ###   ########.fr       */
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

void	arrange_stacks(t_list **a, t_list **b);
void	arrange_three(t_list **a);

void push_a(t_list **a, t_list **b);
void push_b(t_list **a, t_list **b);
void reverse_rrr(t_list **a, t_list **b);
void reverse_ra(t_list **a);
void reverse_rb(t_list **b);
void rotate_rr(t_list **a, t_list **b);
void rotate_b(t_list **b);
void rotate_a(t_list **a);
void swap_ss(t_list **pa, t_list **pb);
void swap_b(t_list **pb);
void swap_a(t_list **pa);
void ft_lstadd_front (t_list **lst, t_list *new);

t_list	*find_last(t_list *stack);
t_list	*find_min(t_list *stack);
t_list	*find_max(t_list *stack);

int	error_syntax(char *str);
void free_errors(t_list **a);
int	list_len(t_list *stack);

void	init_nodes_a(t_list *a, t_list *b);
void	set_optimal(t_list *stack);
void	current_index(t_list *stack);
void	init_nodes_b(t_list *a, t_list *b);

void	prep_for_push(t_list **stack,t_list *top_node,
						char stack_name);
t_list	*get_optimal_node(t_list *stack);
void init_a(t_list **a, char **argv);
bool	list_is_ordered(t_list *stack);
char **split(char *str, char delimiter);
int main(int argc, char **argv);
void sort_list(t_list **a, t_list **b);
void	free_list(t_list **stack);
int	str_to_int(const char *s);


#endif
