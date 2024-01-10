/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:27:24 by hamzaelouar       #+#    #+#             */
/*   Updated: 2024/01/10 14:20:51 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_stage(t_data *data, t_stage *stage, int r, float ra)
{
	float		sratio;
	t_sprite	*tmp_sprite;

	determine_sprite(data, &tmp_sprite, ra);
	sratio = (float) tmp_sprite->swidth / 32.0;
	stage->angle_diff = data->play->pa - ra;
	if (stage->angle_diff < 0)
		stage->angle_diff += 2 * PI;
	if (stage->angle_diff > 2 * PI)
		stage->angle_diff -= 2 * PI;
	stage->dist = stage->dist * cos(stage->angle_diff);
	stage->line_height = (46 * SCREEN_HEIGHT) / stage->dist;
	stage->spy_rate = (float)tmp_sprite->sheight / (float)stage->line_height;
	stage->spy_rate /= sratio;
	stage->spy_shift = 0;
	if (stage->line_height > SCREEN_HEIGHT)
	{
		stage->spy_shift = (stage->line_height - SCREEN_HEIGHT) / 2.0;
		stage->line_height = SCREEN_HEIGHT;
	}
	stage->v_shift = SCREEN_HEIGHT / 2 - (stage->line_height / 2);
	stage->spy = stage->spy_shift * stage->spy_rate;
	stage->spx = 0;
	draw_sprites(data, r, ra);
}

void	draw_sprites(t_data *data, int r, float ra)
{
	t_sprite	*sprite;

	config_south_north_sprite(data, ra, &sprite);
	config_east_west_sprite(data, ra, &sprite);
	put_sprite(sprite, data, r);
}

void	config_south_north_sprite(t_data *data, float ra, t_sprite **sprite)
{
	if (data->stage->height_rd)
	{
		if (ra >= 0 && ra < PI)
		{
			*sprite = data->so_text;
			data->stage->spx = (int)data->stage->rx % TILE_SIZE;
			data->stage->spx = (TILE_SIZE - 1) - data->stage->spx;
		}
		else
		{
			*sprite = data->no_text;
			data->stage->spx = TILE_SIZE - \
			((int)data->stage->rx % TILE_SIZE) - 1;
			data->stage->spx = (TILE_SIZE - 1) - data->stage->spx;
		}
	}
}

void	config_east_west_sprite(t_data *data, float ra, t_sprite **sprite)
{
	if (!data->stage->height_rd)
	{
		if (ra >= PI / 2 && ra < 3 * PI / 2)
		{
			*sprite = data->we_text;
			data->stage->spx = TILE_SIZE - \
			((int)data->stage->ry % TILE_SIZE) - 1;
		}
		else
		{
			*sprite = data->ea_text;
			data->stage->spx = (int)data->stage->ry % TILE_SIZE;
		}
	}
}

void	put_sprite(t_sprite *sprite, t_data *data, int r)
{
	int		i;
	float	c;
	float	scale;

	scale = (float) sprite->swidth / 32.0;
	i = -1;
	while (++i < data->stage->v_shift)
		put_pixel(data->win, r, i, data->parse->color_ceiling_hexa);
	i--;
	while (++i < data->stage->line_height + data->stage->v_shift)
	{
		c = *(int *)(sprite->addr + (int)(data->stage->spy * scale) \
			* sprite->line_length + (int)(data->stage->spx * scale) \
			* (sprite->bits_per_pixel / 8));
		put_pixel(data->win, r, i, c);
		data->stage->spy += data->stage->spy_rate;
	}
	i--;
	while (++i < SCREEN_HEIGHT)
		put_pixel(data->win, r, i, data->parse->color_floor_hexa);
}
