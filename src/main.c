/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:05:31 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/16 13:23:07 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;
	char	*joined_args;

	if (ac >= 2)
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
			return (1);
		joined_args = join_args(ac, av);
		if (!joined_args)
			return (free(data), 1);
		data->buffer = ft_split(joined_args, ' ');
		free(joined_args);
		if (!data->buffer)
			return (free(data), 1);
		if (parse_input(data) == 0)
			init_stacks(data);
		if (stack_is_sorted(data->stack_a) == -1)
			(turk_sort(data), quit(data, '+'));
		else
			quit(data, '+');
		quit(data, '-');
	}
}
