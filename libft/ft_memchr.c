/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:03:28 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/05 00:06:29 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Searches for the first occurrence of the character 'c' in the first 'n'
 * 	bytes of the memory area 's'.
 *
 * @param s     Pointer to the memory area to be searched.
 * @param c     Character to be searched for.
 * @param n     Number of bytes to be searched.
 * @return      Pointer to the first occurrence of 'c' in 's', or NULL if 'c'
 * 	is not found.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	uc;

	ptr = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n--)
	{
		if (*ptr == uc)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
