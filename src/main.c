/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:05:31 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/16 15:37:23 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_data *data)
{
	if (stack_is_sorted(data->stack_a) == -1)
		sa(data->stack_a, 1);
}

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		*ptr = (unsigned char)c;
		ptr++;
	}
	return (s);
}

static int	is_empty_args(int ac, char **av)
{
	int	i;
	int	j;
	int	has_non_space;

	i = 1;
	while (i < ac)
	{
		has_non_space = 0;
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ' && av[i][j] != '\t')
				has_non_space = 1;
			j++;
		}
		if (!has_non_space)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;
	char	*joined_args;

	if (ac >= 2)
	{
		if (is_empty_args(ac, av))
			return (0);
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
			return (1);
		ft_memset(data, 0, sizeof(t_data));
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
	}
}
