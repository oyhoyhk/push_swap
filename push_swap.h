/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooh <yooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:39:40 by yooh              #+#    #+#             */
/*   Updated: 2022/12/14 08:25:26 by yooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

typedef struct s_stack
{
	int				val;
	int				index;
	struct s_stack *next;
}	t_stack;

typedef struct s_info
{
	int			total_count;
	t_stack		*head_a;
	t_stack		*head_b;
	t_stack		*tail_a;
	t_stack		*tail_b;
	int			count_a;
	int			count_b;
}	t_info;

void	set_stack(t_stack **stack, int *count, int argc, char **argv);
void	push_back(t_stack **head, int val);
void	set_index(t_stack *stack);
void	do_ss(t_stack **a, t_stack **b, t_info *info);
void	do_sb(t_stack **b, t_info *info);
void	do_sa(t_stack **a, t_info *info);
void	do_pa(t_stack **a, t_stack **b, t_info *info);
void	do_pb(t_stack **a, t_stack **b, t_info *info);
void	do_ra(t_stack **a, t_info *info);
void	do_rb(t_stack **b, t_info *info);
void	do_rr(t_stack **a, t_stack **b, t_info *info);
void	do_rra(t_stack **a, t_info *info);
void	do_rrb(t_stack **b, t_info *info);
void	do_rrr(t_stack **a, t_stack **b, t_info *info);

#endif