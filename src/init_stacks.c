/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:51:04 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/14 13:11:03 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_data *data)
{
	int		i;
	t_stack	*new_node;
	t_stack	*prev_node;


	data->stack_a = NULL;
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
