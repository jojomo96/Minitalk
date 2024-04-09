/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:48:28 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/04 23:24:16 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Sets the first 'n' bytes of the memory pointed to by 's' to zero.
 *
 * @param s     Pointer to the memory to be zeroed.
 * @param n     Number of bytes to be zeroed.
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
