/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:03:55 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/04 18:22:43 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks if the given character is a printable character.
 *

	* A character is considered printable if it is any character that can be printed
 * on the screen, including letters, digits, punctuation marks, and whitespace.
 *
 * @param c The character to be checked.
 * @return 1 if the character is printable, 0 otherwise.
 */
int	ft_isprint(int c)
{
	return (' ' <= c && c <= '~');
}
