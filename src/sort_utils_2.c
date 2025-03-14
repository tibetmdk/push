/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:50:22 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/14 22:55:10 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_data *data, int print)
{
	t_stack	*head;
	t_stack	*tail;

	if (!data->stack_b || !data->stack_b->next)
		return ;

	head = data->stack_b;
	data->stack_b = data->stack_b->next;
	data->stack_b->prev = NULL;
	tail = data->stack_b;
	while (tail->next)
		tail = tail->next;
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
	if (print)
		ft_printf("rb\n");
}

void	rra(t_data *data ,int print)
{
	t_stack	*tail;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	tail = data->stack_a;
	while (tail->next)
		tail = tail->next;
	tail->prev->next = NULL;
	tail->next = data->stack_a;
	data->stack_a->prev = tail;
	tail->prev = NULL;
	data->stack_a = tail;
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_data *data ,int print)
{
	t_stack	*tail;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	tail = data->stack_b;
	while (tail->next)
		tail = tail->next;
	tail->prev->next = NULL;
	tail->next = data->stack_b;
	data->stack_b->prev = tail;
	tail->prev = NULL;
	data->stack_b = tail;
	if (print)
		ft_printf("rrb\n");
}

void	rr(t_data *data, int print)
{
	ra(data, 0);
	rb(data, 0);
	if (print)
		ft_printf("rr\n");
}

void	rrr(t_data *data, int print)
{
	rra(data, 0);
	rrb(data, 0);
	if (print)
		ft_printf("rrr\n");
}
