/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:11:58 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 10:23:12 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

static void	reverse_string(char *str, int length)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

static void	convert_num_to_str(int num, char *str, int *str_index)
{
	int	rem;

	while (num != 0)
	{
		rem = num % 10;
		if (rem > 9)
			str[(*str_index)++] = (rem - 10) + 'a';
		else
			str[(*str_index)++] = rem + '0';
		num = num / 10;
	}
}

static void	ft_int_to_str(int num, char *str, int *str_index)
{
	int	is_negative;

	if (num == 0)
	{
		str[(*str_index)++] = '0';
		return ;
	}
	is_negative = 0;
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	convert_num_to_str(num, str, str_index);
	if (is_negative)
		str[(*str_index)++] = '-';
	reverse_string(str, *str_index);
}

void	handle_minus(char *res, double *n, int *i)
{
	if (*n < 0)
	{
		res[0] = '-';
		*n = -(*n);
		*i = 1;
	}
}

char	*ft_dtoa(double n, int afterpoint)
{
	char	*res;
	int		ipart;
	double	fpart;
	int		i;

	res = malloc(1 + 20 + 1 + afterpoint + 1);
	if (!res)
		return (NULL);
	ipart = (int)n;
	fpart = n - (double)ipart;
	i = 0;
	handle_minus(res, &n, &i);
	ft_int_to_str(ipart, res + i, &i);
	if (afterpoint > 0)
	{
		res[i++] = '.';
		fpart = fabs(fpart * pow(10.0, afterpoint));
		ft_int_to_str((int)fpart, res + i, &i);
	}
	res[i] = '\0';
	return (res);
}
