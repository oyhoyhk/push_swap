/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooh <yooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:02:44 by yooh              #+#    #+#             */
/*   Updated: 2022/12/14 14:50:30 by yooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_stack **a, t_info *info)
{
	t_stack	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = *a;
	if ((*a)->next == NULL)
		temp->next = NULL;
	*a = (*a)->next;
	info->head_a = *a;
	write(1, "sa\n", 3);
}

void	do_sb(t_stack **b, t_info *info)
{
	t_stack	*temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = *b;
	if ((*b)->next == NULL)
		temp->next = NULL;
	*b = (*b)->next;
	info->head_b = *b;
	write(1, "sb\n", 3);
}

void	do_ss(t_stack **a, t_stack **b, t_info *info)
{
	t_stack *temp;

	if (!(*a == NULL || (*a)->next == NULL))
	{
		temp = *a;
		if ((*a)->next == NULL)
			temp->next = NULL;
		*a = (*a)->next;
		info->head_a = *a;
	}
	if (!(*b == NULL || (*b)->next == NULL))
	{
		temp = *b;
		if ((*b)->next == NULL)
			temp->next = NULL;
		*b = (*b)->next;
		info->head_b = *b;
	}
	write(1, "ss\n", 3);
}

void	do_pa(t_stack **a, t_stack **b, t_info *info)
{
	t_stack	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	if (*b == NULL)
	{
		info->head_b = NULL;
		info->tail_b = NULL;
	}
	if (*a == NULL)
		info->tail_a = temp;
	temp->next = *a;
	*a = temp;
	info->head_a = temp;
	info->count_a++;
	info->count_b--;
}

void	do_pb(t_stack **a, t_stack **b, t_info *info)
{
	t_stack *temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	if (*a == NULL)
	{
		info->head_a = NULL;
		info->tail_a = NULL;
	}
	if (*b == NULL)
		info->tail_b = temp;
	temp->next = *b;
	*b = temp;
	info->head_b = temp;
	info->count_a--;
	info->count_b++;
}