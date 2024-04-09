/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:09:00 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/06 23:34:39 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Applies the function `f` to each character of the string `s` to
 * create a new string resulting from successive applications of `f`.
 *
 * @param s The string to iterate over.
 * @param f The function to apply to each character.
 *          The function takes an unsigned integer representing the index
 *          of the character and the character itself as arguments, and returns
 *          a new character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	if (!s || !(*f))
		return ;
	index = 0;
	while (s[index])
	{
		(*f)(index, &s[index]);
		index++;
	}
}
