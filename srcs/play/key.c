/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:12:43 by hamzaelouar       #+#    #+#             */
/*   Updated: 2024/01/10 14:20:30 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press_hook(int keycode, t_data *data)
{
	if (keycode >= 0 && keycode < 65365)
		data->play->keys[keycode] = true;
	return (0);
}

int	key_release_hook(int keycode, t_data *data)
{
	if (keycode >= 0 && keycode < 65365)
		data->play->keys[keycode] = false;
	return (0);
}

bool	collision_detect(t_data *data, float updx, float updy)
{
	int	map_posx;
	int	map_posy;

	map_posx = updx / TILE_SIZE;
	map_posy = updy / TILE_SIZE;
	if (map_posx >= 0 && map_posy >= 0 && \
	map_posy < data->parse->hmap && map_posx < data->parse->wmap && \
	data->parse->map[map_posy][map_posx] == '1')
		return (true);
	return (false);
}
