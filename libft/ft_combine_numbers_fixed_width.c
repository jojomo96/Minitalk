/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combine_numbers_fixed_width.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:32:55 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 10:29:43 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_numstr_with_padding(char *num_str, int padding)
{
	int	i;

	i = 0;
	while (i < padding)
	{
		num_str[i] = ' ';
		i++;
	}
	num_str[padding] = '\0';
}

static void	combine_with_specific_width(char *result, char *num_str,
		char *formatted_num, int width)
{
	ft_strlcat(num_str, formatted_num, width + 1);
	ft_strlcat(result, num_str, 1024);
}

char	*ft_combine_numbers_with_widths(double *numbers, int size, int *widths)
{
	static char	result[1024];
	char		num_str[1024];
	int			i;
	char		*formatted_num;
	int			total_width;

	i = 0;
	total_width = 0;
	ft_bzero(result, sizeof(result));
	while (i < size)
	{
		formatted_num = ft_dtoa(numbers[i], 2);
		ft_bzero(num_str, sizeof(num_str));
		total_width = widths[i];
		init_numstr_with_padding(num_str, total_width
			- ft_strlen(formatted_num));
		combine_with_specific_width(result, num_str, formatted_num,
			total_width);
		if (i < size - 1)
			ft_strlcat(result, "|", sizeof(result));
		free(formatted_num);
		i++;
	}
	return (result);
}
