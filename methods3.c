/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooh <yooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:07:43 by yooh              #+#    #+#             */
/*   Updated: 2022/12/14 07:13:19 by yooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_prev_tail(t_stack *head)
{
	while (head->next->next)
		head = head->next;
	return (head);
}

void	do_rra(t_stack **a, t_info *info)
{
	t_stack	*prev;
	t_stack *temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	prev = get_prev_tail(*a);
	temp = info->tail_a;
	prev->next = NULL;
	temp->next = *a;
	*a = temp;
	info->head_a = temp;
}

void	do_rrb(t_stack **b, t_info *info)
{
	t_stack	*prev;
	t_stack *temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	prev = get_prev_tail(*b);
	temp = info->tail_b;
	prev->next = NULL;
	temp->next = *b;
	*b = temp;
	info->head_b = temp;
}

void	do_rrr(t_stack **a, t_stack **b, t_info *info)
{
	t_stack	*prev;
	t_stack	*temp;

	if (*a == NULL || (*a)->next == NULL
		|| *b == NULL || (*b)->next == NULL)
	return ;
	prev = get_prev_tail(*a);
	temp = info->tail_a;
	prev->next = NULL;
	temp->next = *a;
	*a = temp;
	info->head_a = temp;
	prev = get_prev_tail(*b);
	temp = info->tail_b;
	prev->next = NULL;
	temp->next = *b;
	*b = temp;
	info->head_b = temp;
}