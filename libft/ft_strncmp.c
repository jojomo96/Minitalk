/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:02:24 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/04 23:33:33 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compares at most the first 'n' characters of two strings 's1' and 's2'.
 *
 * @param s1 The first string to be compared.
 * @param s2 The second string to be compared.
 * @param n The maximum number of characters to compare.
 * @return An integer greater than, equal to, or less than 0,
 *	depending on the comparison result.
 *	- A value greater than 0 indicates that the first 'n' characters of 's1'
 *			are greater than the first 'n' characters of 's2'.
 *	- A value less than 0 indicates that the first 'n' characters of 's1' are
 *			less than the first 'n' characters of 's2'.
 *	- A value of 0 indicates that the first 'n' characters of 's1' are equal
 *		to the first 'n' characters of 's2'.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2 || !*s1 || !*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}
