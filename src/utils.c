/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:54:00 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/14 11:57:38 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quit(t_data *data, char flag)
{
	if (data->stack_a)
		free(data->stack_a);
	if (data->stack_b)
		free(data->stack_b);
	if (data)
		free(data);
	if (flag == '+')
		exit(EXIT_SUCCESS);
	if (flag == '-')
		exit(EXIT_FAILURE);
	if (flag == 'e')
	{
		write(1, "error\n", 7);
		exit(EXIT_FAILURE);
	}
}
