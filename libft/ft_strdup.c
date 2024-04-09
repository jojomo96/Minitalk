/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:11:27 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/06 11:34:42 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Duplicates a string.
 *
 * The ft_strdup function duplicates the string pointed to by s1. It allocates
 * sufficient memory for a copy of the string, does the copy, and returns a
 * pointer to it. The pointer may subsequently be used as an argument to the
 * function free(3).
 *
 * @param s1 The string to be duplicated.
 * @return A pointer to the duplicated string, or NULL if insufficient memory
 * is available.
 */
char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s1) + 1;
	ptr = malloc(len);
	if (!ptr)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_memcpy(ptr, s1, len);
	return (ptr);
}
