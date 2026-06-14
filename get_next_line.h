/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42.sg>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:58:55 by akaung            #+#    #+#             */
/*   Updated: 2026/06/14 21:16:16 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl_list
{
	char				*buffer;
	struct s_gnl_list	*next;
}						t_gnl_list;

int						len_to_new_line(t_gnl_list *list);
char					*get_next_line(int fd);
void					copy_str(t_gnl_list *list, char *str);
char					*get_line(t_gnl_list *list);
void					create_list(t_gnl_list **list, int fd);
int						found_line(t_gnl_list *list);
void					append(t_gnl_list **list, char *buffer);
void					free_all(t_gnl_list **list, t_gnl_list *clean_node,
							char *buffer);
void					polish(t_gnl_list **list);
int						clear_list(t_gnl_list **list, t_gnl_list **last,
							int *i);

#endif
