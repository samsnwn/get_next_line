#include "get_next_line.h"

int	is_newline(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str[i] && i < BUFFER_SIZE)
		{
			if (list->str[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}

void	ft_lstadd_back(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str = buffer;
	new_node->next = NULL;
}

t_list	*ft_lstlast(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	str_len(t_list *list)
{
	int	i;
	int	length;

	length = 0;
	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				++length;
				return (length);
			}
			++i;
			++length;
		}
		list = list->next;
	}
	return (length);
}

void	copy_str(t_list *list, char *str)
{
	int	i;
	int	k;

	if (list == NULL)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = list->str[i++];
		}
		list = list->next;
	}
	str[k] = '\0';
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
