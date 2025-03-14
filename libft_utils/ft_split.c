/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:39:04 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/02 17:51:39 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

static	int	count_words(const char *str, char sep)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != sep && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*str == sep)
			in_word = 0;
		str++;
	}
	return (count);
}

static	char	*get_next_word(const char **s, char c)
{
	const char	*start;
	size_t		word_len;

	while (**s == c && **s != '\0')
		(*s)++;
	start = *s;
	while (**s != c && **s != '\0')
		(*s)++;
	word_len = *s - start;
	return (ft_substr(start, 0, word_len));
}

static	void	free_words(char **words, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	words_count;
	size_t	i;

	if (!s)
		return (NULL);
	words_count = count_words(s, c);
	words = (char **)malloc((words_count + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	while (i < words_count)
	{
		words[i] = get_next_word(&s, c);
		if (!words[i])
		{
			free_words(words, i);
			return (NULL);
		}
		i++;
	}
	words[i] = NULL;
	return (words);
}
