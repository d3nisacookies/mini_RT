/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42.sg>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:58:50 by akaung            #+#    #+#             */
/*   Updated: 2026/06/14 21:17:52 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len_to_new_line(t_gnl_list *list)
{
	int	i;
	int	len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->buffer[i])
		{
			if (list->buffer[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}

void	append(t_gnl_list **list, char *buffer)
{
	t_gnl_list	*node;
	t_gnl_list	*tmp;

	node = malloc(sizeof(t_gnl_list));
	if (!node)
		return ;
	node->buffer = buffer;
	node->next = NULL;
	if (!*list)
	{
		*list = node;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

int	found_line(t_gnl_list *list)
{
	int	i;

	if (!list)
		return (0);
	if (!list->buffer)
	{
		return (0);
	}
	while (list)
	{
		i = 0;
		while (list->buffer[i])
		{
			if (list->buffer[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

void	free_all(t_gnl_list **list, t_gnl_list *clean_node, char *buffer)
{
	t_gnl_list	*tmp;

	if (NULL == *list)
	{
		return ;
	}
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->buffer);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->buffer[0])
		*list = clean_node;
	else
	{
		free(buffer);
		free(clean_node);
	}
}

int	clear_list(t_gnl_list **list, t_gnl_list **last, int *i)
{
	t_gnl_list	*tmp;

	*last = *list;
	while ((*last)->next)
		*last = (*last)->next;
	*i = 0;
	while ((*last)->buffer[*i] && (*last)->buffer[*i] != '\n')
		(*i)++;
	if ((*last)->buffer[*i])
		return (0);
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->buffer);
		free(*list);
		*list = tmp;
	}
	return (1);
}
