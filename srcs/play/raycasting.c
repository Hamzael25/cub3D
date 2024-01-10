/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:00:37 by hamzaelouar       #+#    #+#             */
/*   Updated: 2024/01/10 14:20:45 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ray_cast(t_data *data, t_stage *stage)
{
	int		r;

	stage->ra = data->play->pa - DEGREES_TO_RADIANS * TILE_SIZE;
	r = -1;
	while (++r < SCREEN_WIDTH)
	{
		check_horizontal(stage, data);
		check_vertical(stage, data);
		set_line(stage);
		draw_stage(data, stage, r, stage->ra);
		stage->ra += DEGREES_TO_RADIANS * (FIELDOFVIEW / SCREEN_WIDTH);
		if (stage->ra < 0)
			stage->ra += 2 * PI;
		if (stage->ra > 2 * PI)
			stage->ra -= 2 * PI;
	}
}

void	check_horizontal(t_stage *s, t_data *d)
{
	init_horizontal(s, d);
	calcul_horizontal(s, d);
	while (s->measure < d->parse->gmap)
	{
		s->mapx = (int)(s->rx / TILE_SIZE);
		s->my = (int)(s->ry / TILE_SIZE);
		if (s->mapx >= 0 && s->mapx < d->parse->wmap && s->my >= 0
			&& s->my < d->parse->hmap
			&& s->mapx < (int)ft_strlen(d->parse->map[s->my])
			&& s->my < (int)ft_tablen(d->parse->map)
			&& d->parse->map[s->my][s->mapx] == '1')
		{
			s->hx = s->rx;
			s->hy = s->ry;
			s->hdist = calcul_dist(d->play->posx, d->play->posy, s->hx, s->hy);
			s->measure = d->parse->gmap;
		}
		else
		{
			s->rx += s->xo;
			s->ry += s->yo;
			s->measure += 1;
		}
	}
}

void	init_horizontal(t_stage *s, t_data *d)
{
	s->measure = 0;
	s->hdist = 100000000;
	s->hx = d->play->posx;
	s->hy = d->play->posy;
}

void	calcul_horizontal(t_stage *stage, t_data *d)
{
	float	ang_tan;

	ang_tan = -1 / tan(stage->ra);
	if (stage->ra > PI)
	{
		stage->ry = (float)(((int)d->play->posy / TILE_SIZE) * \
		TILE_SIZE) - 0.0001;
		stage->rx = (d->play->posy - stage->ry) * ang_tan + d->play->posx;
		stage->yo = -TILE_SIZE;
		stage->xo = -stage->yo * ang_tan;
	}
	else if (stage->ra < PI)
	{
		stage->ry = (float)(((int)d->play->posy / TILE_SIZE) * \
		TILE_SIZE) + TILE_SIZE;
		stage->rx = (d->play->posy - stage->ry) * ang_tan + d->play->posx;
		stage->yo = TILE_SIZE;
		stage->xo = -stage->yo * ang_tan;
	}
	else
	{
		stage->rx = d->play->posx;
		stage->ry = d->play->posy;
		stage->measure = d->parse->gmap;
	}
}

void	set_line(t_stage *stage)
{
	stage->height_rd = 1;
	if (stage->vdist < stage->hdist)
	{
		stage->rx = stage->vx;
		stage->ry = stage->vy;
		stage->dist = stage->vdist;
		stage->height_rd = 0;
	}
	else
	{
		stage->rx = stage->hx;
		stage->ry = stage->hy;
		stage->dist = stage->hdist;
	}
}
