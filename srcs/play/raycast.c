/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:21:23 by hamzaelouar       #+#    #+#             */
/*   Updated: 2024/01/10 14:20:18 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_vertical(t_stage *s, t_data *d)
{
	calcul_vertical(s, d);
	init_vertical(s, d);
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
			s->vx = s->rx;
			s->vy = s->ry;
			s->vdist = calcul_dist(d->play->posx, d->play->posy, s->vx, s->vy);
			break ;
		}
		else
		{
			s->rx += s->xo;
			s->ry += s->yo;
			s->measure += 1;
		}
	}
}

void	init_vertical(t_stage *s, t_data *d)
{
	s->measure = 0;
	s->vx = d->play->posx;
	s->vy = d->play->posy;
	s->vdist = 1000000;
}

void	calcul_vertical(t_stage *stage, t_data *data)
{
	float	n_tan;

	n_tan = -tan(stage->ra);
	if (stage->ra > PI / 2 && stage->ra < 3 * PI / 2)
	{
		stage->rx = (float)(((int)data->play->posx / TILE_SIZE) * \
		TILE_SIZE) - 0.0001;
		stage->ry = (data->play->posx - stage->rx) * n_tan + data->play->posy;
		stage->xo = -TILE_SIZE;
		stage->yo = -stage->xo * n_tan;
	}
	else if (stage->ra < PI / 2 || stage->ra > 3 * PI / 2)
	{
		stage->rx = (float)(((int)data->play->posx / TILE_SIZE) * \
		TILE_SIZE) + TILE_SIZE;
		stage->ry = (data->play->posx - stage->rx) * n_tan + data->play->posy;
		stage->xo = TILE_SIZE;
		stage->yo = -stage->xo * n_tan;
	}
	else
	{
		stage->rx = data->play->posx;
		stage->ry = data->play->posy;
		stage->measure = data->parse->gmap;
	}
}
