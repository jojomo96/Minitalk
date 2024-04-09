/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:44:12 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/06 23:37:58 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	dest_bigger_than_src(unsigned char *dst_c, unsigned char *src_c,
		size_t len)
{
	while (len > 0)
	{
		dst_c[len - 1] = src_c[len - 1];
		len--;
	}
}

/**
 * Copies a block of memory from a source address to a destination address,
 * handling overlapping memory regions correctly.
 *
 * @param dst   Pointer to the destination address where the
 * 				memory will be copied to.
 * @param src   Pointer to the source address where the memory
 *				will be copied from.
 * @param len   Number of bytes to be copied.
 *
 * @return      Pointer to the destination address.
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_c;
	unsigned char	*src_c;
	size_t			i;

	dst_c = (unsigned char *)dst;
	src_c = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	i = 0;
	if (dst_c > src_c)
	{
		dest_bigger_than_src(dst_c, src_c, len);
	}
	else
	{
		while (i < len)
		{
			dst_c[i] = src_c[i];
			i++;
		}
	}
	return (dst);
}
