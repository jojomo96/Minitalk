/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:53:40 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/04 23:27:50 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies a string from `src` to `dst`, up to `dstsize` characters.
 *
 * This function copies at most `dstsize
	- 1` characters from the string `src` to `dst`,
 * and ensures that `dst` is null-terminated. If `dstsize` is 0,
	`dst` will not be modified.
 *
 * @param dst The destination buffer where the string will be copied to.
 * @param src The source string to be copied.
 * @param dstsize The size of the destination buffer.
 * @return The total length of the string that was attempted to be copied.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
