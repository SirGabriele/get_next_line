/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:37:42 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/11 14:27:45 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_lstnew(int entry_fd)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (elem == NULL)
		return (NULL);
	elem->fd = entry_fd;
	elem->buf = NULL;
	elem->line = NULL;
	elem->tdl = 0;
	elem->i = 0;
	elem->hmb_read = 0;
	elem->nb_of_read = 0;
	elem->next = NULL;
	return (elem);
}

t_list	*ft_go_to_link(t_list **first_elem, int fd)
{
	t_list	*copy;
	t_list	*new;

	copy = *first_elem;
	new = NULL;
	while (copy != NULL && copy->fd != fd)
		copy = copy->next;
	if (copy == NULL)
	{
		new = ft_lstnew(fd);
		ft_lst_addback(first_elem, new);
		return (new);
	}
	return (copy);
}

void	ft_lst_addback(t_list **first_elem, t_list *new)
{
	t_list	*copy;

	copy = *first_elem;
	if (*first_elem == NULL)
		*first_elem = new;
	if (new == NULL)
		return ;
	else
	{
		while (copy->next != NULL)
			copy = copy->next;
		copy->next = new;
	}
}

int	check_string(char *str)
{
	int	i;

	i = -1;
	if (str == NULL)
		return (0);
	while (str[++i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
	}
	return (0);
}

void	*ft_calloc(int size)
{
	char	*tab;
	int		i;

	i = -1;
	tab = malloc(sizeof(char) * size);
	if (tab == NULL)
		return (NULL);
	while (++i < size)
		tab[i] = '\0';
	return ((char *)tab);
}
