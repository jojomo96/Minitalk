/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:49:06 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/05 20:52:53 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Concatenates the string pointed to by `src` to the end of the string
 * pointed to by `dst`. It will append at most `dstsize - strlen(dst) - 1`
 * characters from `src` and null-terminate the result.
 *
 * @param dst      The destination string.
 * @param src      The source string.
 * @param dstsize  The size of the destination buffer.
 * @return         The total length of the string that would have been created
 *                 if enough space had been available, excluding the null
 *                 termination character.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	j = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	if (dstsize < dst_len)
		return (src_len + dstsize);
	while (dst[i] && i < dstsize - 1)
		i++;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
