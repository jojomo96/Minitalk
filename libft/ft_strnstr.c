/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:07:28 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/04 23:35:07 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Searches for the first occurrence of the substring 'needle' in the
 * string 'haystack', but only searches within the first 'len' characters
 * of 'haystack'.
 *
 * @param	haystack The string to search within.
 * @param	needle The substring to search for.
 * @param	len The maximum number of characters to search within 'haystack'.
 * @return	(If 'needle' is an empty string, 'haystack' is returned);
 *			if 'needle' occurs nowhere in 'haystack', NULL is returned;
 *			otherwise, a pointer to the first character of the first
 *			occurrence of 'needle' in 'haystack' is returned.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	needle_len = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len >= needle_len)
	{
		i = 0;
		while (needle[i] && needle[i] == haystack[i])
			i++;
		if (!needle[i])
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
