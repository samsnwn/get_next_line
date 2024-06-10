/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:28:23 by samcasti          #+#    #+#             */
/*   Updated: 2024/06/10 18:28:25 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
int					is_newline(t_list *list);
t_list				*ft_lstlast(t_list *list);
int					str_len(t_list *list);
void				copy_str(t_list *list, char *str);
void				free_list(t_list **list, t_list *clean_node, char *buf);
char				*get_line(t_list *list);
void				clean_list(t_list **list);
void				ft_lstadd_back(t_list **list, char *buffer);
void				create_node(t_list **list, int fd);

#endif
