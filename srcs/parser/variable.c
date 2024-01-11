/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalzentout <bilalzentout@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:44:47 by hel-ouar          #+#    #+#             */
/*   Updated: 2024/01/10 19:12:44 by bilalzentou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_variable(t_parse *parse, char **split_line)
{
	if (set_sprite(parse, split_line) && set_color(parse, split_line))
		return (1);
	return (0);
}

int	set_sprite(t_parse *parse, char **split_line)
{
	if (!ft_strncmp(split_line[0], "WE\0", 3) && !parse->we)
	{
		if (get_sprite(&parse->we, split_line))
			return (1);
	}
	else if (!ft_strncmp(split_line[0], "EA\0", 3) && !parse->ea)
	{
		if (get_sprite(&parse->ea, split_line))
			return (1);
	}
	else if (!ft_strncmp(split_line[0], "SO\0", 3) && !parse->so)
	{
		if (get_sprite(&parse->so, split_line))
			return (1);
	}
	else if (!ft_strncmp(split_line[0], "NO\0", 3) && !parse->no)
	{
		if (get_sprite(&parse->no, split_line))
			return (1);
	}
	else
		return (1);
	return (0);
}

int	get_sprite(char **path, char **split_line)
{
	*path = ft_strndup(split_line[1], ft_strlen(split_line[1]) - 1);
	if (!*path)
		return (1);
	return (0);
}

int	set_color(t_parse *parse, char **split_line)
{
	if (!ft_strncmp(split_line[0], "C\0", 2))
	{
		if (split_line[1] && get_color(parse, split_line[1], 1))
			return (1);
	}
	else if (!ft_strncmp(split_line[0], "F\0", 2))
	{
		if (split_line[1] && get_color(parse, split_line[1], 0))
			return (1);
	}
	else
		return (1);
	return (0);
}

int	get_color(t_parse *parse, char *color, int flg)
{
	char	**split_color;
	int		i;

	i = -1;
	split_color = ft_split4(color);
	if (!split_color)
		return (ft_free_tab(split_color), 1);
	if (check_color(split_color, color, 0, 0))
		return (ft_free_tab(split_color), 1);
	while (split_color[++i])
	{
		if (flg)
		{
			parse->ceiling = "s";
			parse->color_ceiling[i] = ft_atoi(split_color[i]);
		}
		else
		{
			parse->floor = "s";
			parse->color_floor[i] = ft_atoi(split_color[i]);
		}
	}
	ft_free_tab(split_color);
	return (0);
}
