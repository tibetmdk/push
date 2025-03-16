/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost_a_to_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:28:07 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/16 13:12:00 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bring_to_top_a(t_data *data)
{
	t_stack	*a;
	int		pos;
	int		len;

	len = get_stack_len(data->stack_a);
	a = data->stack_a;
	while (a)
	{
		pos = get_index(data->stack_a, a->value);
		if (pos <= len / 2)
			a->ra = pos;
		else
			a->rra = len - pos;
		a = a->next;
	}
}

static void	bring_target_top_b(t_data *data)
{
	t_stack	*a;
	int		pos;
	int		len_b;

	len_b = get_stack_len(data->stack_b);
	a = data->stack_a;
	while (a)
	{
		pos = find_max_under_value(data->stack_b, a->value);
		if (pos <= (len_b / 2))
			a->rb = pos;
		else
			a->rrb = len_b - pos;
		a = a->next;
	}
}

static void	set_cost(t_data *data)
{
	t_stack	*ptr;
	int		rr;
	int		rrr;

	ptr = data->stack_a;
	while (ptr)
	{
		rr = 0;
		rrr = 0;
		while (ptr->ra > 0 && ptr->rb > 0)
		{
			rr++;
			ptr->ra--;
			ptr->rb--;
		}
		while (ptr->rra > 0 && ptr->rrb > 0)
		{
			rrr++;
			ptr->rra--;
			ptr->rrb--;
		}
		ptr->push_cost = rr + rrr + ptr->ra + ptr->rb + ptr->rra + ptr->rrb;
		ptr = ptr->next;
	}
}

static void	find_cheapest_in_a(t_data *data)
{
	t_stack	*cheapest;
	int		index;
	int		len_a;
	int		len_b;

	len_a = get_stack_len(data->stack_a);
	len_b = get_stack_len(data->stack_b);
	cheapest = find_cheapest(data->stack_a);
	index = get_index(data->stack_a, cheapest->value);
	if (index <= (len_a / 2))
		data->ra = index;
	else
		data->rra = len_a - index;
	index = find_max_under_value(data->stack_b, cheapest->value);
	if (index <= (len_b / 2))
		data->rb = index;
	else
		data->rrb = len_b - index;
}

void	calculate_cost_a_to_b(t_data *data)
{
	reset_costs(data);
	bring_to_top_a(data);
	bring_target_top_b(data);
	set_cost(data);
	find_cheapest_in_a(data);
}
