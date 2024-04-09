/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:22:58 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 17:54:55 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

const char	*process_digits(const char *str, double *result, int decimal,
		int decimal_count)
{
	while (ft_isdigit(*str) || *str == '.')
	{
		if (*str == '.')
		{
			decimal = 1;
			str++;
			continue ;
		}
		if (decimal)
		{
			*result = *result + (*str - '0') * pow(10, -decimal_count);
			decimal_count++;
		}
		else
			*result = *result * 10 + (*str - '0');
		str++;
	}
	return (str);
}

double	ft_strtod(const char *str, char **endptr)
{
	double	result;
	int		sign;
	int		decimal;
	int		decimal_count;

	result = 0;
	sign = 1;
	decimal = 0;
	decimal_count = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	str = process_digits(str, &result, decimal, decimal_count);
	if (endptr)
		*endptr = (char *)str;
	return (result * sign);
}
