/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooh <yooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:39:02 by yooh              #+#    #+#             */
/*   Updated: 2022/12/18 09:55:09 by yooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	show_stack(t_stack *stack);
void show(t_stack *a, t_stack *b);

t_stack *get_tail(t_stack *a)
{
	if (a == NULL)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

void	move_a_to_b(t_stack **a, t_stack **b, int total_count)
{
	int		div;
	int		i;

	div = total_count / 3;
	i = 0;
	while (i <total_count)
	{
		if ((*a)->index < div)
		{
			do_push(b, a, 'b');
			do_rotate(b, 'b');
		}
		else if ((*a)->index < div * 2)
			do_push(b, a, 'b');
		else
			do_rotate(a, 'a');
		i++;
	}
	i = get_stack_length(*a);
	while (i > 3)
	{
		do_push(b, a, 'b');
		i--;
	}
	sort_three(a);
}

int	is_sort(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	count_index(t_stack *a, int index)
{
	int		i;
	int		a_len;

	i = 0;
	a_len = get_stack_length(a);
	while (a->index < index)
	{
		i++;
		a = a->next;
	}
	if (i > a_len / 2)
		i = (a_len - i) * (-1);
	return (i);
}

int main(int argc, char **argv)
{
	static t_stack		*a;
	static t_stack		*b;
	int					total_count;

	set_stack(&a, &total_count, argc, argv);
	set_index(a);
	move_a_to_b(&a, &b, total_count);

	show(a, b);
	t_stack *cur;

	cur = b;
	int	position;
	while (cur)
	{
		position = count_index(a, cur->index);
		printf("position : %d\n", position);
		cur = cur->next;
	}
}

static void	show_stack(t_stack *stack)
{
	int		i;
	
	i = 0;
	while (stack)
	{
		printf("%d : [index : %d]\n", i, stack->index);
		i++;
		stack = stack->next;
	}
}

void show(t_stack *a, t_stack *b)
{
	printf("--------stack_a-------------\n");
	show_stack(a);
	printf("--------stack_b-------------\n");
	show_stack(b);
}