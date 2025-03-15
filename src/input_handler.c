/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:02:05 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/16 01:29:03 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == 32 || str[i] == '\t')
			i++;
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		while (str[i] == 32 || str[i] == '\t')
			i++;
		if (str[i] != '\0')
			return (1);
	}
	return (0);
}

static int	number_count(t_data *data)
{
	int	i;

	i = 0;
	while (data->buffer[i])
		i++;
	return (i);
}

static int	is_equal(int *arr, int size, int num, int index)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i != index && arr[i] == num)
			return (1);
		i++;
	}
	return (0);
}

int	*parse_input(t_data *data)
{
	int	i;

	data->tab_size = number_count(data);
	data->tab = (int *)malloc(sizeof(int) * data->tab_size);
	if (!data->tab)
		return (NULL);
	i = 0;
	while (data->buffer[i])
	{
		if (number_is_valid(data->buffer[i]))
			quit(data, 'e');
		data->tab[i] = ft_atol(data->buffer[i]);
		i++;
	}
	i = 0;
	while (i < data->tab_size)
	{
		if (is_equal(data->tab, data->tab_size, data->tab[i], i))
			quit(data, 'e');
		i++;
	}
	return (0);
}

char	*join_args(int ac, char **av)
{
	int		i;
	char	*joined;
	char	*temp;

	i = 1;
	joined = ft_strdup("");
	while (i < ac)
	{
		temp = ft_strjoin(joined, av[i]);
		free(joined);
		joined = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	return (joined);
}
