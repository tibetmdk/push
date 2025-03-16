/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost_b_to_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:41:59 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/16 13:53:07 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	bring_to_top_b(t_data *data)
{
	t_stack	*b;
	int		pos;
	int		len_b;

	len_b = get_stack_len(data->stack_b);
	b = data->stack_b;
	while (b)
	{
		pos = get_index(data->stack_b, b->value);
		if (pos <= (len_b / 2))
			b->push_cost += pos;
		else
			b->push_cost += len_b - pos;
		b = b->next;
	}
}

static void	bring_target_top_a(t_data *data)
{
	t_stack	*b;
	int		pos;
	int		len_a;

	len_a = get_stack_len(data->stack_a);
	b = data->stack_b;
	while (b)
	{
		pos = find_min_on_value(data->stack_a, b->value);
		if (pos <= (len_a / 2))
			b->push_cost += pos;
		else
			b->push_cost += len_a - pos;
		b = b->next;
	}
}

static void	set_costs(t_data *data)
{
	t_stack	*ptr;
	int		rr;
	int		rrr;

	ptr = data->stack_b;
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

static void	find_cheapest_in_b(t_data *data)
{
	t_stack	*cheapest;
	int		index;
	int		len_b;
	int		len_a;

	len_a = get_stack_len(data->stack_a);
	len_b = get_stack_len(data->stack_b);
	cheapest = find_cheapest(data->stack_b);
	index = get_index(data->stack_b, cheapest->value);
	if (index <= (len_b / 2))
		data->rb = index;
	else
		data->rrb = len_b - index;
	index = find_min_on_value(data->stack_a, cheapest->value);
	if (index <= (len_a / 2))
		data->ra = index;
	else
		data->rra = len_a - index;
}

void	calculate_cost_b_to_a(t_data *data)
{
	reset_costs(data);
	bring_to_top_b(data);
	bring_target_top_a(data);
	set_costs(data);
	find_cheapest_in_b(data);
}
