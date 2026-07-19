/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:03:01 by akaung            #+#    #+#             */
/*   Updated: 2026/06/16 15:03:03 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_RT.h"

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	check_token(char *token)
{
	int	i;
	int	dot;

	if (!token || !token[0])
		return (0);
	i = 0;
	dot = 0;
	if (token[i] == '-')
		i++;
	if (!token[i])
		return (0);
	while (token[i])
	{
		if (token[i] == '.' && !dot)
			dot = 1;
		else if (token[i] < '0' || token[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
