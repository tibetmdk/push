/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:42:31 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/02 17:50:27 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

size_t	ft_strlcpy(char *destination, const char *source, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (source[i])
			i++;
		return (i);
	}
	while (i < size - 1 && source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	if (i < size)
		destination[i] = '\0';
	while (source[i] != '\0')
		i++;
	return (i);
}
