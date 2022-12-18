/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooh <yooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 08:25:30 by yooh              #+#    #+#             */
/*   Updated: 2022/12/18 09:11:52 by yooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	const int	first = (*a)->index;
	const int	second = (*a)->next->index;
	const int	third = (*a)->next->next->index;

	if (first < second && third < second)
	{
		if (first < third)
		{
			do_rotate(a, 'a');
			do_switch(a, 'a');
		}
		do_reverse_rotate(a, 'a');
	}
	else if (first > second && third > second)
	{
		if (first < third)
			do_switch(a, 'a');
		else
			do_rotate(a, 'a');
	}
	else
	{
		do_switch(a, 'a');
		do_reverse_rotate(a, 'a');
	}
}

void	sort_two(t_stack **stack)
{
	if ((*stack)->index > (*stack)->next->index)
		do_switch(stack, 'a');	
}