/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:27:48 by samcasti          #+#    #+#             */
/*   Updated: 2024/06/26 13:24:07 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int main()
// {
// 	int fd;
// 	char *line;
// 	int lines;

// 	lines = 1;
// 	fd = open("test.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)))
// 		printf("%d-> %s\n", lines++, line);
// 	close(fd);
// 	return 0;
// }

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	create_node(&list, fd);
	if (list == NULL)
		return (NULL);
	line = ft_get_line(list);
	clean_list(&list);
	return (line);
}

void	create_node(t_list **list, int fd)
{
	int		bytes_read;
	char	*buffer;

	while (!is_newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(buffer);
			return ;
		}
		buffer[bytes_read] = '\0';
		ft_lstadd_back(list, buffer);
	}
}

char	*ft_get_line(t_list *list)
{
	int		length;
	char	*line;

	if (list == NULL)
		return (NULL);
	length = str_len(list);
	line = malloc(length + 1);
	if (line == NULL)
		return (NULL);
	copy_str(list, line);
	return (line);
}

void	clean_list(t_list **list)
{
	t_list	*last_node;
	t_list	*new_node;
	int		i;
	int		k;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	new_node = malloc(sizeof(t_list));
	if (buffer == NULL || new_node == NULL)
		return ;
	last_node = ft_lstlast(*list);
	i = 0;
	k = 0;
	while (last_node->str[i] && last_node->str[i] != '\n')
		++i;
	while (last_node->str[i] && last_node->str[++i])
		buffer[k++] = last_node->str[i];
	buffer[k] = '\0';
	new_node->str = buffer;
	new_node->next = NULL;
	free_list(list, new_node, buffer);
}

void	free_list(t_list **list, t_list *new_node, char *buffer)
{
	t_list	*tmp;

	if (*list == NULL)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (new_node->str[0])
		*list = new_node;
	else
	{
		free(buffer);
		free(new_node);
	}
}
