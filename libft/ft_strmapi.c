/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:40:16 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/05 20:04:19 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Applies the function `f` to each character of the string `s` to
 * create a new string resulting from successive applications of `f`.
 *
 * @param s The string to iterate over.
 * @param f The function to apply to each character.
 *          The function takes an unsigned integer representing the index
 * 		    of the character and the character itself as arguments, and returns
 *          a new character.
 * @return The new string created by applying `f` to each character of `s`.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*new_str;

	if (!s || !f)
		return (NULL);
	new_str = ft_strdup(s);
	if (!new_str)
		return (NULL);
	index = 0;
	while (new_str[index])
	{
		new_str[index] = f(index, new_str[index]);
		index++;
	}
	return (new_str);
}
