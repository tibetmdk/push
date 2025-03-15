/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:48:17 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/16 01:23:19 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_len(t_stack *stack)
{
	t_stack *temp;
	int	count;

	count = 0;
	temp = stack;
	while (temp)
	{
			count++;
			temp = temp->next;
	}
	return (count);
}

int	stack_is_sorted(t_stack *stack)
{
	t_stack	*temp;
	temp = stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (-1);
		temp = temp->next;
	}
	return (1);
}

void	init_stacks(t_data *data)
{
	int		i;
	t_stack	*new_node;
	t_stack	*prev_node;


	data->stack_a = NULL;
	data->stack_b = NULL;
	prev_node = NULL;
	i = 0;
	while (i < data->tab_size)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		if (!new_node)
			return ;
		new_node->value = data->tab[i];
		new_node->next = NULL;
		new_node->prev = prev_node;
		if (prev_node)
			prev_node->next = new_node;
		else
			data->stack_a = new_node;
		prev_node = new_node;
		i++;
	}
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
