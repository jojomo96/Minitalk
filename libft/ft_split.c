/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:38:21 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/07 13:31:59 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static int	ft_word_length(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static void	free_array(char **arr, int size)
{
	while (size--)
	{
		free(arr[size]);
	}
	free(arr);
}

static char	**ft_allocate_words(char const *s, char c, int word_count,
		t_iterators it)
{
	char	**arr;
	int		len;
	int		char_in_word_index;

	arr = (char **)ft_calloc(word_count + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	while (it.word_index < word_count)
	{
		while (s[it.char_index] == c)
			it.char_index++;
		len = ft_word_length(s + it.char_index, c);
		arr[it.word_index] = (char *)ft_calloc(len + 1, sizeof(char));
		if (!arr[it.word_index])
		{
			free_array(arr, it.word_index);
			return (NULL);
		}
		char_in_word_index = 0;
		while (char_in_word_index < len)
			arr[it.word_index][char_in_word_index++] = s[it.char_index++];
		arr[it.word_index++][char_in_word_index] = '\0';
		it.char_index += (s[it.char_index] != '\0');
	}
	return (arr);
}

/**
 * Splits a string into an array of substrings based on a delimiter character.
 *
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return An array of strings representing the substrings.
 */
char	**ft_split(char const *s, char c)
{
	int			word_count;
	t_iterators	it;

	it.char_index = 0;
	it.word_index = 0;
	if (!s)
		return (NULL);
	word_count = ft_count_words(s, c);
	return (ft_allocate_words(s, c, word_count, it));
}
