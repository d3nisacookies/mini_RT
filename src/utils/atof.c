/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:59:35 by akaung            #+#    #+#             */
/*   Updated: 2026/06/16 14:59:35 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_RT.h"

double	ft_atof(const char *nptr)
{
	double	result;
	int		sign;
	double	divider;

	result = 0.0;
	sign = 1;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
		result = result * 10.0 + (*nptr++ - '0');
	if (*nptr == '.')
	{
		nptr++;
		divider = 10.0;
		while (*nptr >= '0' && *nptr <= '9')
		{
			result += (*nptr++ - '0') / divider;
			divider *= 10.0;
		}
	}
	return (result * sign);
}
