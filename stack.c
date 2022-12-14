/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooh <yooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:50:05 by yooh              #+#    #+#             */
/*   Updated: 2022/12/13 10:56:18 by yooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_new_node(int val)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(t_stack));
	if (!new)
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		exit(1);
	}
	new->index = -1;
	new->val = val;
	new->next = NULL;
	return (new);
}

void	push_back(t_stack **head, int val)
{
	t_stack		*cur;
	t_stack		*new;

	new = create_new_node(val);
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}