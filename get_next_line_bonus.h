/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:35:48 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/11 14:27:35 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			*buf;
	char			*line;
	int				tdl;
	int				i;
	int				hmb_read;
	int				nb_of_read;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	ft_read_file_and_fill_buf(t_list *temp);
void	ft_fill_line(t_list *temp);
char	*ft_increase_string_size(t_list *temp);
char	*ft_erase_link(t_list **first_elem, t_list *temp);

t_list	*ft_lstnew(int entry_fd);
t_list	*ft_go_to_link(t_list **first_elem, int fd);
void	ft_lst_addback(t_list **first_elem, t_list *new);
int		check_string(char *str);
void	*ft_calloc(int size);

#endif
