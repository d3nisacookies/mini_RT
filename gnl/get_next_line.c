/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42.sg>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:58:43 by akaung            #+#    #+#             */
/*   Updated: 2026/06/14 21:16:02 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//#include <stdio.h>

void	polish(t_gnl_list **list)
{
	t_gnl_list	*last;
	t_gnl_list	*clean;
	char		*rem;
	int			i;
	int			k;

	if (!list || !*list)
		return ;
	if (clear_list(list, &last, &i))
		return ;
	rem = malloc(BUFFER_SIZE + 1);
	if (!rem)
		return ;
	k = 0;
	while (last->buffer[++i])
		rem[k++] = last->buffer[i];
	rem[k] = '\0';
	clean = malloc(sizeof(t_gnl_list));
	if (!clean)
		return (free(rem));
	clean->buffer = rem;
	clean->next = NULL;
	free_all(list, clean, rem);
}

void	create_list(t_gnl_list **list, int fd)
{
	int		char_read;
	char	*buffer;

	while (!found_line(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buffer);
			break ;
		}
		buffer[char_read] = '\0';
		append(list, buffer);
	}
}

char	*get_line(t_gnl_list *list)
{
	int		len;
	char	*str;

	if (!list)
		return (NULL);
	len = len_to_new_line(list);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	copy_str(list, str);
	return (str);
}

void	copy_str(t_gnl_list *list, char *str)
{
	int	i;
	int	k;

	if (!list)
	{
		return ;
	}
	k = 0;
	while (list)
	{
		i = 0;
		while (list->buffer[i])
		{
			str[k++] = list->buffer[i];
			if (list->buffer[i++] == '\n')
			{
				str[k] = '\0';
				return ;
			}
		}
		list = list->next;
	}
	str[k] = '\0';
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*list;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list(&list, fd);
	if (!list)
		return (NULL);
	line = get_line(list);
	polish(&list);
	return (line);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int fd;
// 	char *line;
// 	int lines;

// 	lines = 1;
// 	fd = open("test.txt", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 		{
// 			break ;
// 		}
// 		printf("%d-> %s\n", lines++, line);
// 		free(line);
// 	}
// 	return (0);
// }