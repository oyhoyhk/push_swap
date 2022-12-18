/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooh <yooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:39:40 by yooh              #+#    #+#             */
/*   Updated: 2022/12/18 09:29:45 by yooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TO_STACK_A	0
# define TO_STACK_B	1

#include "libft/libft.h"

#include <stdio.h>

typedef struct	s_stack
{
	int				val;
	int				index;
	struct s_stack *next;
}	t_stack;

typedef struct	s_info
{
	int		a;
	int		b;
	int		after_a;
	int		index;
}	t_info;

void	set_stack(t_stack **stack, int *count, int argc, char **argv);
void	push_back(t_stack **head, int val);
void	set_index(t_stack *stack);
void	do_reverse_rotate_both(t_stack **a, t_stack **b);
void	do_rotate_both(t_stack **a, t_stack **b);
void	do_reverse_rotate(t_stack **stack, char ch);
void	do_rotate(t_stack **stack, char ch);
void	do_switch(t_stack **stack, char ch);
void	do_push(t_stack **in, t_stack **out, char ch);
int		get_stack_length(t_stack *stack);
void	sort_three(t_stack **a);
void	do_best(t_stack **a, t_stack **b, t_info best);

void	 show(t_stack *a, t_stack *b);

#endif