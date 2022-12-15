/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooh <yooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:29:15 by yooh              #+#    #+#             */
/*   Updated: 2022/12/15 17:41:48 by yooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_switch(t_stack **stack, char ch)
{
	t_stack		*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	if (ch == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	do_rotate(t_stack **stack, char ch)
{
	t_stack		*temp;
	t_stack		*prev_tail;
	
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	prev_tail = *stack;
	while (prev_tail->next)
		prev_tail = prev_tail->next;
	prev_tail->next = temp;
	temp->next = NULL;
	if (ch == 'a')
		write(1, "ra\n", 3);
	else if(ch == 'b')
		write(1, "rb\n", 3);
}

void	do_reverse_rotate(t_stack **stack, char ch)
{
	t_stack		*temp;
	t_stack		*prev_tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	prev_tail = *stack;
	while (prev_tail->next->next)
		prev_tail = prev_tail->next;
	temp = prev_tail->next;
	prev_tail->next = NULL;
	temp->next = *stack;
	*stack = temp;
	if (ch == 'a')
		write(1, "rra\n", 4);
	else if(ch == 'b')
		write(1, "rrb\n", 4);
}

void	do_rotate_both(t_stack **a, t_stack **b)
{
	do_rotate(a, 'r');
	do_rotate(b, 'r');
	write(1, "rr\n", 3);
}

void	do_reverse_rotate_both(t_stack **a, t_stack **b)
{
	do_reverse_rotate(a, 'r');
	do_reverse_rotate(b, 'r');
	write(1, "rrr\n", 4);
}