/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:44:47 by hel-ouar          #+#    #+#             */
/*   Updated: 2024/01/11 13:50:30 by hel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parsing(char *map, t_data *data)
{
	if (check_file(map, "buc.") || check_open_file(data, map, 1, 0))
		return (1);
	if (parsing_map(data->parse))
		return (ft_putstr_fd("Error\nMap Wrong1\n", 2), 1);
	if (check_map(data->parse->map))
		return (ft_putstr_fd("Error\nMap Wrong2\n", 2), 1);
	set_color_c_f(data);
	if (check_path(data))
		return (1);
	return (0);
}

int	check_file(char *map, char *ext)
{
	char	**tmp;
	char	*filename;

	tmp = ft_split_cub(map, '/');
	if (!tmp)
		return (ft_free_tab(tmp), 1);
	filename = tmp[ft_strlen_dtab(tmp) - 1];
	while (*filename)
		filename++;
	filename--;
	while (*filename == *ext)
	{
		filename--;
		ext++;
	}
	if (*ext)
		return (ft_putstr_fd("Error\nWrong extension\n", 2), \
			ft_free_tab(tmp), 1);
	return (ft_free_tab(tmp), 0);
}

int	check_open_file(t_data *data, char *file, int flg, int cl)
{
	int	fd;

	if (access(file, F_OK) != -1)
	{
		if (access(file, R_OK) == -1)
			return (ft_putstr_fd("Error\nPemission File\n", 2), 1);
	}
	else if (flg == 1)
		return (ft_putstr_fd("Error\nFile not Found\n", 2), 1);
	else if (flg == 2)
		return (ft_putstr_fd("Error\nTexture not Found\n", 2), 1);
	fd = open(file, O_RDONLY);
	assign_fd(data, cl, fd);
	if (fd < 1)
		return (ft_putstr_fd("Error\nfailed to open file\n", 2), 1);
	if (flg == 1)
	{
		if (check_valid_file(data->parse, fd))
			return (data->parse->fdmap = fd, 1);
	}
	return (0);
}

int	parsing_map(t_parse *parse)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (parse->map[i])
	{
		if (check_char(parse->map[i], &p, parse))
			return (1);
		if (ft_strchr(parse->map[i], ' '))
			space_to_x(parse->map[i]);
		i++;
	}
	if (p != 1)
		return (1);
	if (no_wall_or_space(parse->map[0])
		|| no_wall_or_space(parse->map[ft_strlen_dtab(parse->map) - 1])
		|| check_wall(parse, 0, 0, 0) || check_player(parse->map))
		return (1);
	return (0);
}

void	set_color_c_f(t_data *data)
{
	int	r;
	int	g;
	int	b;

	r = data->parse->color_ceiling[0];
	g = data->parse->color_ceiling[1];
	b = data->parse->color_ceiling[2];
	data->parse->color_ceiling_hexa = (r * 65536) + (g * 256) + b;
	r = data->parse->color_floor[0];
	g = data->parse->color_floor[1];
	b = data->parse->color_floor[2];
	data->parse->color_floor_hexa = (r * 65536) + (g * 256) + b;
}
