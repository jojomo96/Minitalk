/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:25:09 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/09 19:32:40 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Sets the first 'len' bytes of the memory area pointed to by 'b' to
 * the value of 'c'.
 *
 * @param b		Pointer to the memory area to be filled.
 * @param c		Value to be set. The value is passed as an int,
 * 				but the function fills the memory area using the
 * 				unsigned char conversion of this value.
 * @param len 	Number of bytes to be set to the value of 'c'.
 *
 * @return A pointer to the memory area 'b'.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
