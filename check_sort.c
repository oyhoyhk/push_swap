/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooh <yooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 06:56:15 by yooh              #+#    #+#             */
/*   Updated: 2022/12/19 06:57:41 by yooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_asc_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
	}
	return (1);
}

int	is_desc_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->index < stack->next->index)
			return (0);
	}
	return (1);
}