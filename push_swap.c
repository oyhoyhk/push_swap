/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooh <yooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:39:02 by yooh              #+#    #+#             */
/*   Updated: 2022/12/19 12:48:23 by yooh             ###   ########.fr       */
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
	int		i;

	i = 0;
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (i);
		stack = stack->next;
		i++;
	}
	return (0);
}

int	find_left_index(t_stack *a, int index)
{
	int			i;
	const int	a_len = get_stack_length(a);

	i = 0;
	while (a && a->index < index)
	{
		i++;
		a = a->next;
	}
	if (i > a_len / 2)
		i = (a_len - i) * (-1);
	return (i);
}

t_info	count_info(t_stack *a, t_stack *b, int index, int i)
{
	t_info	info;
	int		right_pos;
	int		b_len;

	info.a = find_left_index(a, index);
	right_pos = i;
	b_len = get_stack_length(b);
	if (i > b_len / 2)
		right_pos = (b_len - i) * -1;
	info.b = right_pos;
	info.index = index;
	return (info);
}

t_info	compare_info(t_info a, t_info b)
{
	int	sum_a;
	int sum_b;

	sum_a = 0;
	if (a.a > 0)
		sum_a += a.a;
	else
		sum_a += a.a * (-1);
	if (a.b >0)
		sum_a += a.b;
	else
		sum_a += a.b * (-1);
	sum_b = 0;
	if (b.a > 0)
		sum_b += b.a;
	else
		sum_b += b.a * (-1);
	if (b.b > 0)
		sum_b += b.b;
	else
		sum_b += b.b * (-1);
	if (sum_a <= sum_b)
		return (a);
	return (b);
}

t_info	find_best(t_stack *a, t_stack *b)
{
	t_stack *cur;
	t_info	temp;
	t_info	min;
	int		i;

	i = 1;
	min = count_info(a, b, b->index, 0);
	cur = b->next;
	while (cur)
	{
		temp = count_info(a, b, cur->index, i);
		min = compare_info(min, temp);
		i++;
		cur = cur->next;
	}
	return (min);
}

void	do_best(t_stack **a, t_stack **b, t_info info)
{
	int		i;

	if (info.a >= 0 && info.b >= 0)
	{
		i = 0;
		while (i < info.a)
		{
			do_rotate(a, 'a');
			i++;
		}
		i = 0;
		while (i < info.b)
		{
			do_rotate(b, 'b');
			i++;
		}
	}
	else if (info.a <= 0 && info.b >= 0)
	{
		i = 0;
		info.a *= -1;
		while (i < info.a)
		{
			do_reverse_rotate(a, 'a');
			i++;
		}
		i = 0;
		while (i < info.b)
		{
			do_rotate(b, 'b');
			i++;
		}
	}
	else if (info.a >= 0 && info.b <= 0)
	{
		i = 0;
		while (i < info.a)
		{
			do_rotate(a, 'a');
			i++;
		}
		i = 0;
		info.b *= -1;
		while (i < info.b)
		{
			do_reverse_rotate(b, 'b');
			i++;
		}
	}
	else
	{
		i = 0;
		info.a *= -1;
		while (i < info.a)
		{
			do_reverse_rotate(a, 'a');
			i++;
		}
		i = 0;
		info.b *= -1;
		while (i < info.b)
		{
			do_reverse_rotate(b, 'b');
			b++;
		}
	}
}


int main(int argc, char **argv)
{
	static t_stack		*a;
	static t_stack		*b;
	int					total_count;
	t_info				best;

	set_stack(&a, &total_count, argc, argv);
	set_index(a);
	move_a_to_b(&a, &b, total_count);

	while (b)
	{
		show(a,b );
		best = find_best(a, b);
		printf("best, index : %d, info.a : %d, info.b %d\n", best.index, best.a, best.b);
		do_best(&a, &b, best);
		do_push(&a, &b, 'a');
		show(a, b);
	}
	printf("%d, %d, %d\n", best.a, best.b, best.index);
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