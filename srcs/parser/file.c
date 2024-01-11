/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalzentout <bilalzentout@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:44:47 by hel-ouar          #+#    #+#             */
/*   Updated: 2024/01/10 19:12:33 by bilalzentou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	variable(char *line, t_parse *parse, int *flg)
{
	char	**split_line;

	split_line = ft_split_cub(line, ' ');
	if (!split_line)
		return (ft_free_tab(split_line), 1);
	if (*split_line[0] == ' ' && !split_line[1])
		return (ft_free_tab(split_line), 0);
	if (split_line[1])
	{
		if (get_variable(parse, split_line))
			return (ft_free_tab(split_line), 1);
	}
	else
		return (ft_free_tab(split_line), 1);
	if (!valid_variable(parse))
		*flg = 1;
	return (ft_free_tab(split_line), 0);
}

int	get_cell_map(t_map **tmp_map, char *line)
{
	t_map	*cell;

	cell = create_cell_map(line);
	if (!cell)
		return (1);
	ft_lstadd_back_map(tmp_map, cell);
	return (0);
}

int	get_map(t_map **tmp_map, t_parse *parse)
{
	int			i;
	t_map		*head;

	head = *tmp_map;
	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	parse->map = malloc(sizeof(char **) * (i + 1));
	if (!parse->map)
		return (1);
	i = 0;
	head = *tmp_map;
	while (head)
	{
		parse->map[i] = ft_strdup(head->line);
		if (!parse->map[i])
			return (1);
		i++;
		head = head->next;
	}
	parse->map[i] = 0;
	return (0);
}

int	valid_variable(t_parse *parse)
{
	if (!parse->ea || !parse->no || !parse->so
		|| !parse->we || !parse->floor || !parse->ceiling)
		return (1);
	return (0);
}

int	check_valid_file(t_parse *parse, int fd)
{
	char		*line;
	int			flg;
	t_map		*tmp_map;

	flg = 0;
	line = NULL;
	tmp_map = NULL;
	while (42)
	{
		if (line)
			free(line);
		line = get_next_line_gnl(fd);
		if (!line)
		{
			if (valid_variable(parse) || get_map(&tmp_map, parse))
				return (ft_putstr_fd("Error in file\n", 2), \
					lstclear_map(&tmp_map), 1);
			return (free(line), lstclear_map(&tmp_map), 0);
		}
		if (flg)
			if (get_cell_map(&tmp_map, line))
				return (free(line), 1);
		if (!flg && variable(line, parse, &flg))
			return (ft_putstr_fd("Error in file\n", 2), free(line), 1);
	}
}
