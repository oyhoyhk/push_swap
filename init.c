/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooh <yooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:43:41 by yooh              #+#    #+#             */
/*   Updated: 2022/12/14 07:15:38 by yooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_argv(t_stack **stack, int *count, char *str);

void	set_stack(t_stack **stack, int *count, int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		parse_argv(stack, count, argv[i]);
		i++;
	}
}

void	set_index(t_stack *stack)
{
	t_stack	*cur;
	t_stack	*top;
	t_stack	*temp;
	int		i;

	top = stack;
	cur = top;
	while (cur)
	{
		i = 0;
		temp = top;
		while (temp)
		{
			if (cur->val > temp->val)
				i++;
			temp = temp->next;
		}
		cur->index = i;
		cur = cur->next;
	}
}

static void	check_number(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
		{
			write(2, "Error\n", ft_strlen("Error\n"));
			exit(1);
		}
		i++;
	}
}

static void	parse_argv(t_stack **stack, int *count, char *str)
{
	char	**result;
	int		i;

	result = ft_split(str, ' ');
	i = 0;
	while (result[i])
	{
		check_number(result[i]);
		push_back(stack, ft_atoi(result[i]));
		i++;
		*count += 1;
	}
}