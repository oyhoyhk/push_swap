/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooh <yooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:42:31 by yooh              #+#    #+#             */
/*   Updated: 2022/12/15 17:45:54 by yooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_push(t_stack **in, t_stack **out, char ch)
{
	t_stack	*temp;

	if (*out == NULL)
		return ;
	temp = *out;
	*out = (*out)->next;
	temp->next = *in;
	*in = temp;
	if (ch == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

int	get_stack_length(t_stack *stack)
{
	int		i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}