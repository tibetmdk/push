/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:54:00 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/16 13:07:42 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quit(t_data *data, char flag)
{
	int	i;

	if (data->stack_a)
		free_stack(data->stack_a);
	if (data->stack_b)
		free_stack(data->stack_b);
	if (data)
	{
		if (data->buffer)
		{
			i = 0;
			while (data->buffer[i])
				free(data->buffer[i++]);
			free(data->buffer);
		}
		if (data->tab)
			free(data->tab);
		free(data);
	}
	if (flag == '+')
		exit(EXIT_SUCCESS);
	if (flag == '-')
		exit(EXIT_FAILURE);
	if (flag == 'e')
		(write(1, "error\n", 7), exit(EXIT_FAILURE));
}

t_stack	*find_cheapest(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*cheapest;

	temp = stack;
	cheapest = temp;
	while (temp)
	{
		if (temp->push_cost < cheapest->push_cost)
			cheapest = temp;
		temp = temp->next;
	}
	return (cheapest);
}

int	get_index(t_stack *stack, int value)
{
	t_stack	*temp;
	int		index;

	index = 0;
	temp = stack;
	while (temp)
	{
		if (temp->value == value)
			return (index);
		index++;
		temp = temp->next;
	}
	return (-1);
}

int	find_max_under_value(t_stack *stack, int value)
{
	t_stack	*temp;
	t_stack	*best_match;
	int		index;
	int		target_index;

	index = 0;
	target_index = -1;
	temp = stack;
	best_match = NULL;
	while (temp)
	{
		if (temp->value < value)
		{
			if (!best_match || temp->value > best_match->value)
			{
				best_match = temp;
				target_index = index;
			}
		}
		index++;
		temp = temp->next;
	}
	if (target_index == -1)
		return (get_index(stack, find_max_in_stack(stack)->value));
	return (target_index);
}

void	reset_costs(t_data *data)
{
	t_stack	*a;
	t_stack	*b;

	a = data->stack_a;
	b = data->stack_b;
	while (a)
	{
		a->push_cost = 0;
		a->ra = 0;
		a->rb = 0;
		a->rra = 0;
		a->rrb = 0;
		a = a->next;
	}
	while (b)
	{
		b->push_cost = 0;
		b->ra = 0;
		b->rb = 0;
		b->rra = 0;
		b->rrb = 0;
		b = b->next;
	}
}
