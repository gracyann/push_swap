/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotoa <arakotoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:21:50 by arakotoa          #+#    #+#             */
/*   Updated: 2024/11/26 18:29:09 by arakotoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct s_list
{
	long			nb;
	int				i;
	int				operation_count;
	bool			optimal_node;
	bool			above_median;
	struct s_list	*match_node;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

void	arrange_stacks(t_list **a, t_list **b);
void	arrange_three(t_list **a);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	reverse_rrr(t_list **a, t_list **b);
void	reverse_ra(t_list **a);
void	reverse_rb(t_list **b);
void	rotate_rr(t_list **a, t_list **b);
void	rotate_b(t_list **b);
void	rotate_a(t_list **a);
void	swap_ss(t_list **pa, t_list **pb);
void	swap_b(t_list **pb);
void	swap_a(t_list **pa);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	calculate_stack_operation(t_list *a, t_list *b);
void	bring_min_on_top(t_list **a);
void	init_nodes_a(t_list *a, t_list *b);
void	set_optimal(t_list *stack);
void	current_index(t_list *stack);
void	init_nodes_b(t_list *a, t_list *b);
void	prep_for_push(t_list **stack, t_list *top_node, char stack_name);
void	set_match_b(t_list *a, t_list *b);
void	init_a(int argc, char **argv, t_list **pile_a);
void	sort_list(t_list **a, t_list **b);
void	free_list(t_list **stack);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);

t_list	*set_optimal_b(t_list *stack);
t_list	*find_last(t_list *stack);
t_list	*find_min(t_list *stack);
t_list	*find_max(t_list *stack);
t_list	*ft_lstnew(long content);
t_list	*ft_lstlast(t_list *lst);
t_list	*get_optimal_node(t_list *stack);

int		list_len(t_list *stack);
int		checking_if_sorted(t_list *lst);
int		checking_no_digit(int argc, char **argv);
int		check_duplicates(t_list *lst);
int		checking_overflow(t_list *lst);

bool	list_is_ordered(t_list *stack);

#endif
