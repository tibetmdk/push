/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:00:52 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/16 13:06:08 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max_in_stack(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*max;

	max = stack;
	temp = stack;
	while (temp)
	{
		if (temp->value > max->value)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

t_stack	*find_min_in_stack(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*min;

	min = stack;
	temp = stack;
	while (temp)
	{
		if (temp->value < min->value)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

int	find_min_on_value(t_stack *stack, int value)
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
		if (temp->value > value)
		{
			if (!best_match || temp->value < best_match->value)
			{
				best_match = temp;
				target_index = index;
			}
		}
		index++;
		temp = temp->next;
	}
	if (target_index == -1)
		return (get_index(stack, find_min_in_stack(stack)->value));
	return (target_index);
}
