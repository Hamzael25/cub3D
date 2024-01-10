/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:49:06 by hamzaelouar       #+#    #+#             */
/*   Updated: 2024/01/10 14:20:34 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move(t_data *data)
{
	float	smove;
	float	srotate;
	float	safe_marg;
	float	updx;
	float	updy;

	smove = 0.6;
	srotate = 0.04;
	safe_marg = 6.0;
	updx = data->play->posx;
	updy = data->play->posy;
	update_position(data, smove, &updx, &updy);
	check_collision(data, updx, updy, safe_marg);
	update_angle(data, srotate);
	handle_esc_key(data);
}

void	update_position(t_data *data, float smove, float *updx, float *updy)
{
	if (data->play->keys[W])
	{
		*updx += data->play->px * smove;
		*updy += data->play->py * smove;
	}
	if (data->play->keys[S])
	{
		*updx -= data->play->px * smove;
		*updy -= data->play->py * smove;
	}
	if (data->play->keys[A])
	{
		*updx -= cos(data->play->pa + PI / 2) * smove * 3;
		*updy -= sin(data->play->pa + PI / 2) * smove * 3;
	}
	if (data->play->keys[D])
	{
		*updx += cos(data->play->pa + PI / 2) * smove * 3;
		*updy += sin(data->play->pa + PI / 2) * smove * 3;
	}
}

void	check_collision(t_data *data, float updx, float updy, \
float s_marg)
{
	if (!collision_detect(data, updx, data->play->posy) && \
	!collision_detect(data, updx - s_marg, data->play->posy - s_marg) && \
	!collision_detect(data, updx - s_marg, data->play->posy + s_marg) && \
	!collision_detect(data, updx + s_marg, data->play->posy - s_marg) && \
	!collision_detect(data, updx + s_marg, data->play->posy + s_marg))
		data->play->posx = updx;
	if (!collision_detect(data, data->play->posx, updy) && \
	!collision_detect(data, data->play->posx - s_marg, updy - s_marg) && \
	!collision_detect(data, data->play->posx - s_marg, updy + s_marg) && \
	!collision_detect(data, data->play->posx + s_marg, updy - s_marg) && \
	!collision_detect(data, data->play->posx + s_marg, updy + s_marg))
		data->play->posy = updy;
}

void	update_angle(t_data *data, float srotate)
{
	if (data->play->keys[LEFT])
	{
		data->play->pa -= srotate;
		if (data->play->pa < 0)
			data->play->pa += 2 * PI;
		data->play->px = cos(data->play->pa) * 5;
		data->play->py = sin(data->play->pa) * 5;
	}
	if (data->play->keys[RIGHT])
	{
		data->play->pa += srotate;
		if (data->play->pa > 2 * PI)
			data->play->pa -= 2 * PI;
		data->play->px = cos(data->play->pa) * 5;
		data->play->py = sin(data->play->pa) * 5;
	}
}

void	handle_esc_key(t_data *data)
{
	if (data->play->keys[ESC])
	{
		ft_free_all(data, 1);
		exit(0);
	}
}
