/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:04:58 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/05 10:26:22 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compares the first `n` bytes of memory areas `s1` and `s2`.
 *
 * @param s1    Pointer to the first memory area.
 * @param s2    Pointer to the second memory area.
 * @param n     Number of bytes to compare.
 *
 * @return      An integer less than, equal to, or greater than zero if
 *              the first `n` bytes of `s1` are found,
 *              respectively, to be less than, to match, or be greater
 *              than the first `n` bytes of `s2`.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}
