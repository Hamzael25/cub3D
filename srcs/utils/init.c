/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:44:47 by hel-ouar          #+#    #+#             */
/*   Updated: 2024/01/10 14:19:56 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_struct(t_data *data)
{
	data->parse = ft_calloc(1, sizeof(t_parse));
	data->play = ft_calloc(1, sizeof(t_play));
	data->win = ft_calloc(1, sizeof(t_win));
	data->no_text = ft_calloc(1, sizeof(t_sprite));
	data->so_text = ft_calloc(1, sizeof(t_sprite));
	data->ea_text = ft_calloc(1, sizeof(t_sprite));
	data->we_text = ft_calloc(1, sizeof(t_sprite));
	data->stage = ft_calloc(1, sizeof(t_stage));
	if (!data->parse || !data->play)
		return (0);
	ft_bzero(data->parse, sizeof(t_parse));
	ft_bzero(data->play, sizeof(t_play));
	ft_bzero(data->win, sizeof(t_win));
	ft_bzero(data->no_text, sizeof(t_sprite));
	ft_bzero(data->so_text, sizeof(t_sprite));
	ft_bzero(data->ea_text, sizeof(t_sprite));
	ft_bzero(data->we_text, sizeof(t_sprite));
	ft_bzero(data->stage, sizeof(t_stage));
	return (1);
}

int	init_struct_data(t_data *data)
{
	if (data->parse->orientation == 'N')
		data->play->pa = 3 * PI / 2;
	else if (data->parse->orientation == 'S')
		data->play->pa = PI / 2;
	else if (data->parse->orientation == 'E')
		data->play->pa = 0;
	else if (data->parse->orientation == 'W')
		data->play->pa = PI;
	data->play->posx = (get_position(1, data->parse->map) * 30) + 15;
	data->play->posy = (get_position(0, data->parse->map) * 30) + 15;
	data->play->px = cos(data->play->pa) * 5;
	data->play->py = sin(data->play->pa) * 5;
	get_map_size(data->parse);
	data->parse->wmap -= 1;
	if (data->parse->hmap > data->parse->wmap)
		data->parse->gmap = data->parse->hmap;
	else
		data->parse->gmap = data->parse->wmap;
	return (1);
}

int	get_position(int flg, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S' \
				|| map[i][j] == 'W')
			{
				if (flg)
					return (j);
				else
					return (i);
			}
		}
	}
	return (0);
}

void	get_map_size(t_parse *parse)
{
	int	i;
	int	current_length;

	i = -1;
	while (parse->map[++i] != NULL)
	{
		current_length = 0;
		while (parse->map[i][current_length] != '\0')
			++current_length;
		if (current_length > parse->wmap)
			parse->wmap = current_length;
		++parse->hmap;
	}
}

