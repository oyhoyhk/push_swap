/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooh <yooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:39:02 by yooh              #+#    #+#             */
/*   Updated: 2022/12/14 08:26:58 by yooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

static void	show_stack(t_stack *stack);

int main(int argc, char **argv)
{
	static t_stack		*a;
	static t_stack		*b;
	static t_info		info;

	set_stack(&a, &info.total_count, argc, argv);
	set_index(a);
	show_stack(a);
	printf("total_length : %d\n", info.total_count);
	
	int		div_count;
	int		i;

	div_count = (int) info.total_count / 3;
	i = 0;
	while (i < info.total_count)
	{
		if (a->index < div_count)
		{
			do_pb(&a, &b, &info);
			do_rb(&b, &info);
		}
		else if (a->index < div_count * 2)
			do_pb(&a, &b, &info);
		else
			do_ra(&a, &info);
		i++;
	}

	show_stack(a);
	printf("\n\n");
	show_stack(b);
}


static void	show_stack(t_stack *stack)
{
	int		i;
	
	i = 0;
	while (stack)
	{
		printf("%d : [index : %d], [value : %d]\n", i, stack->index, stack->val);
		i++;
		stack = stack->next;
	}
}