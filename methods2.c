/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooh <yooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 06:53:52 by yooh              #+#    #+#             */
/*   Updated: 2022/12/14 07:07:37 by yooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_stack **a, t_info *info)
{
	t_stack	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	info->head_a = *a;
	info->tail_a->next = temp;
	info->tail_a = temp;
	temp->next = NULL;
}

void	do_rb(t_stack **b, t_info *info)
{
	t_stack	*temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	info->head_b = *b;
	info->tail_b->next = temp;
	info->tail_b = temp;
	temp->next = NULL;
}

void	do_rr(t_stack **a, t_stack **b, t_info *info)
{
	t_stack	*temp;

	if (*a == NULL || (*a)->next == NULL
		|| *b == NULL || (*b)->next == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	info->head_a = *a;
	info->tail_a->next = temp;
	info->tail_a = temp;
	temp->next = NULL;
	temp = *b;
	*b = (*b)->next;
	info->head_b = *b;
	info->tail_b->next = temp;
	info->tail_b = temp;
	temp->next = NULL;
	write(1, "rr\n", 3);
}