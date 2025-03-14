/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:45:24 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/15 00:48:31 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b(t_data *data)
{
	calculate_cost_a_to_b(data);
	
}

void	turk_sort(t_data *data)
{
	int	len;

	len = get_stack_len(data->stack_a);
	if (len > 3 && stack_is_sorted(data->stack_a == -1))
		pb(data, 1);
	if (len > 3 && stack_is_sorted(data->stack_a == -1))
		pb(data, 1);
	move_a_to_b(data);
	sort_three(data);
	moveb_to_a(data);
}
