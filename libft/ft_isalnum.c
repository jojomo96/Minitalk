/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:53:56 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/04 23:24:52 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks if the given character is alphanumeric.
 *
 * The ft_isalnum function checks whether the given character is alphanumeric.
 * An alphanumeric character is any uppercase or lowercase letter or digit.
 *
 * @param c The character to be checked.
 * @return Non-zero value if the character is alphanumeric, 0 otherwise.
 */
int	ft_isalnum(int c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c
			&& c <= '9'));
}
