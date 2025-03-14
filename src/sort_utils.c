/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:42:27 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/14 22:45:56 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a, int print)
{
	int	temp;
	
	if (!stack_a || !stack_a->next)
		return ;
	temp = stack_a->value;
	stack_a->value = stack_a->next->value;
	stack_a->next->value = temp;
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack *stack_b, int print)
{
	int	temp;
	
	if (!stack_b || !stack_b->next)
		return ;
	temp = stack_b->value;
	stack_b->value = stack_b->next->value;
	stack_b->next->value = temp;
	if (print)
		ft_printf("sb\n");
}

void	pa(t_data *data, int print)
{
	t_stack	*a;
	t_stack	*b;

	if (!data->stack_b)
		return ;
	a = data->stack_b;
	b = data->stack_b->next;
	if (data->stack_b->next)
		data->stack_b->next->prev = NULL;
	data->stack_b->next = data->stack_a;
	if (data->stack_a)
		data->stack_a->prev = data->stack_b;
	data->stack_b = b;
	data->stack_a = a;
	if (print)
		ft_printf("pa\n");
}

void	pb(t_data *data, int print)
{
	t_stack	*a;
	t_stack	*b;

	if (!data->stack_a)
		return ;
	a = data->stack_a->next;
	b = data->stack_a;

	if (data->stack_a->next)
		data->stack_a->next->prev = NULL;
	data->stack_a->next = data->stack_b;
	if (data->stack_b)
		data->stack_b->prev = data->stack_a;
	data->stack_a = a;
	data->stack_b = b;
	if (print)
		ft_printf("pb\n");
}

void	ra(t_data *data, int print)
{
    t_stack *head;
    t_stack *tail;

    if (!data->stack_a || !data->stack_a->next)
        return ;

    head = data->stack_a;
    data->stack_a = data->stack_a->next;
    data->stack_a->prev = NULL;
    tail = data->stack_a;
    while (tail->next)
        tail = tail->next;
    tail->next = head;
    head->prev = tail;
    head->next = NULL;
    if (print)
        ft_printf("ra\n");
}