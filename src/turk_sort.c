/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:45:24 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/16 15:19:25 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->stack_a->value;
	b = data->stack_a->next->value;
	c = data->stack_a->next->next->value;
	if (a > b && b < c && a < c)
		sa(data->stack_a, 1);
	else if (a > b && b > c)
	{
		sa(data->stack_a, 1);
		rra(data, 1);
	}
	else if (a > b && b < c && a > c)
		ra(data, 1);
	else if (a < b && b > c && a < c)
	{
		sa(data->stack_a, 1);
		ra(data, 1);
	}
	else if (a < b && b > c && a > c)
		rra(data, 1);
}

static void	move_a_to_b(t_data *data)
{
	int	len_a;

	len_a = get_stack_len(data->stack_a);
	while (len_a > 3)
	{
		calculate_cost_a_to_b(data);
		while (data->ra > 0 && data->rb > 0)
			(rr(data, 1), data->ra--, data->rb--);
		while (data->rra > 0 && data->rrb > 0)
			(rrr(data, 1), data->rra--, data->rrb--);
		while (data->ra > 0)
			(ra(data, 1), data->ra--);
		while (data->rra > 0)
			(rra(data, 1), data->rra--);
		while (data->rb > 0)
			(rb(data, 1), data->rb--);
		while (data->rrb > 0)
			(rrb(data, 1), data->rrb--);
		pb(data, 1);
		len_a--;
	}
	sort_three(data);
}

static void	move_b_to_a(t_data *data)
{
	int	len_b;

	len_b = get_stack_len(data->stack_b);
	while (len_b != 0)
	{
		calculate_cost_b_to_a(data);
		while (data->ra > 0 && data->rb > 0)
			(rr(data, 1), data->ra--, data->rb--);
		while (data->rra > 0 && data->rrb > 0)
			(rrr(data, 1), data->rra--, data->rrb--);
		while (data->ra > 0)
			(ra(data, 1), data->ra--);
		while (data->rra > 0)
			(rra(data, 1), data->rra--);
		while (data->rb > 0)
			(rb(data, 1), data->rb--);
		while (data->rrb > 0)
			(rrb(data, 1), data->rrb--);
		pa(data, 1);
		len_b--;
	}
}

static void	final_rotation(t_data *data)
{
	int	min_index;
	int	size;

	min_index = get_index(data->stack_a,
			find_min_in_stack(data->stack_a)->value);
	size = get_stack_len(data->stack_a);
	if (min_index <= size / 2)
	{
		while (min_index-- > 0)
			ra(data, 1);
	}
	else
	{
		while (min_index++ < size)
			rra(data, 1);
	}
}

void	turk_sort(t_data *data)
{
	int	len;

	len = get_stack_len(data->stack_a);
	if (len == 2)
	{
		sort_two(data);
		quit(data, '+');
	}
	if (len > 3)
	{
		pb(data, 1);
		len--;
	}
	if (len > 3)
		pb(data, 1);
	move_a_to_b(data);
	move_b_to_a(data);
	final_rotation(data);
}
