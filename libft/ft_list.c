/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:44:47 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/12/01 17:33:48 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_map	*lstlast_map(t_map *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_map	*create_cell_map(char *line)
{
	t_map	*cell;

	cell = malloc(sizeof(t_map));
	if (!cell)
		return (NULL);
	cell->line = ft_strdup(line);
	cell->next = NULL;
	return (cell);
}

void	ft_lstadd_back_map(t_map **lst, t_map *new)
{
	t_map	*last;

	if (lst)
	{
		if (*lst)
		{
			last = lstlast_map(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}

int	lstsize_map(t_map *lst)
{
	int			i;
	t_map		*cpy;

	cpy = lst;
	i = 0;
	while (cpy)
	{
		cpy = cpy->next;
		i++;
	}
	return (i);
}

void	lstclear_map(t_map **lst)
{
	t_map	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free((*lst)->line);
			free(*lst);
			*lst = tmp;
		}
	}
}
