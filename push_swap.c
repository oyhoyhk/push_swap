/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooh <yooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:39:02 by yooh              #+#    #+#             */
/*   Updated: 2022/12/15 18:19:38 by yooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	show_stack(t_stack *stack);
int	index_of_the_best_node(t_stack *a, t_stack *b);
void show(t_stack *a, t_stack *b);

int get_count(int target_index, t_stack *stack)
{
	int		i;

	i = 0;
	while (stack)
	{
		if (target_index < stack->index)
			break;
		i++;
		stack = stack->next;
	}
	return (i);
}

void	divide_stack_into_three_part(t_stack **a, t_stack **b)
{
	int		total_count;
	int		i;

	total_count = get_stack_length(*a);
	i = 0;
	while (i < total_count)
	{
		if ((*a)->index < total_count / 3)
		{
			do_push(b, a, 'b');
			do_rotate(b, 'b');
		}
		else if ((*a)->index < (total_count / 3) * 2)
			do_push(b, a, 'b');
		else
			do_rotate(a, 'a');
		i++;
	}
	while (*a)
		do_push(b, a, 'b');
}

int		cal_stack_position(t_stack *stack, t_info info)
{
	int		i;

	i = 0;
	while (stack && stack->index < info.index)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int		math_min(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	get_greedy_info(t_stack *a, t_stack *b, t_info *info)
{
	int		a_length;
	int		b_length;
	t_stack	*cur;
	int		a_count;
	int		b_count;

	a_length = get_stack_length(a);
	b_length = get_stack_length(b);
	cur = b;
	while (cur)
	{
		a_count = cal_stack_position(a, *info);
		b_count = cal_stack_position(b, *info);
	}
}

int main(int argc, char **argv)
{
	static t_stack		*a;
	static t_stack		*b;
	int			total_count;

	set_stack(&a, &total_count, argc, argv);
	set_index(a);
	total_count = get_stack_length(a);
	divide_stack_into_three_part(&a, &b);
	show(a, b);


	static t_info	info;
	info.index = b->index;
	t_stack	*cur;
	cur = b;
	while (cur)
	{
		get_greedy_info(a, b, &info);
	}
}

static int	count_stack_a(int target, t_stack *a)
{
	int		i;

	if (a == NULL)
		return (0);
	i = 0;
	while (a && a->index < target)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	index_of_the_best_node(t_stack *a, t_stack *b)
{
	t_stack		*cur;
	int			target;
	int			min_count;
	int			i;
	int			count_a;

	target = -1;
	min_count = 2147483647;
	cur = b;
	i = 0;
	while (cur)
	{
		count_a = count_stack_a(cur->index, a);
		if (i * 2 + count_a < min_count)
		{
			min_count = i + count_a;
			target = cur->index;
		}
		cur = cur->next;
		i++;
	}
	return (target);
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