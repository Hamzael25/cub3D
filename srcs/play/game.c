/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:06:16 by hamzaelouar       #+#    #+#             */
/*   Updated: 2024/01/10 14:20:39 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	start_game(t_win *win, t_data *data)
{
	win->mlx = mlx_init();
	if (!win->mlx)
		return (1);
	win->mlx_w = mlx_new_window(win->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3d");
	if (!win->mlx_w || init_sprite(data, data->parse))
		return (1);
	mlx_hook(data->win->mlx_w, 17, 0, screen_close, data);
	mlx_hook(data->win->mlx_w, 2, 1L << 0, key_press_hook, data);
	mlx_hook(data->win->mlx_w, 3, 1L << 1, key_release_hook, data);
	mlx_loop_hook(win->mlx, random_next_frame, data);
	mlx_loop(win->mlx);
	return (0);
}

int	init_sprite(t_data *d, t_parse *parse)
{
	d->no_text->img = mlx_xpm_file_to_image(d->win->mlx, \
		parse->no, &d->no_text->swidth, &d->no_text->sheight);
	d->so_text->img = mlx_xpm_file_to_image(d->win->mlx, \
		parse->so, &d->so_text->swidth, &d->so_text->sheight);
	d->ea_text->img = mlx_xpm_file_to_image(d->win->mlx, \
		parse->ea, &d->ea_text->swidth, &d->ea_text->sheight);
	d->we_text->img = mlx_xpm_file_to_image(d->win->mlx, \
		parse->we, &d->we_text->swidth, &d->we_text->sheight);
	if (!d->we_text->img || !d->no_text->img || !d->so_text->img \
		|| !d->ea_text->img)
		return (1);
	init_sprites(d);
	return (0);
}

void	init_sprites(t_data *d)
{
	d->no_text->addr = mlx_get_data_addr(d->no_text->img, \
		&d->no_text->bits_per_pixel, &d->no_text->line_length, \
			&d->no_text->endian);
	d->so_text->addr = mlx_get_data_addr(d->so_text->img, \
		&d->so_text->bits_per_pixel, &d->so_text->line_length, \
			&d->so_text->endian);
	d->ea_text->addr = mlx_get_data_addr(d->ea_text->img, \
		&d->ea_text->bits_per_pixel, &d->ea_text->line_length, \
			&d->ea_text->endian);
	d->we_text->addr = mlx_get_data_addr(d->we_text->img, \
		&d->we_text->bits_per_pixel, &d->we_text->line_length, \
			&d->we_text->endian);
}

int	random_next_frame(t_data *data)
{
	data->win->img = mlx_new_image(data->win->mlx, 1920, 1080);
	if (!data->win->img)
		return (ft_free_all(data, 1), exit(0), 1);
	data->win->addr = mlx_get_data_addr(data->win->img,
			&data->win->bits_per_pixel, &data->win->line_length,
			&data->win->endian);
	move(data);
	ray_cast(data, data->stage);
	mlx_put_image_to_window(data->win->mlx, data->win->mlx_w,
		data->win->img, 0, 0);
	mlx_destroy_image(data->win->mlx, data->win->img);
	return (0);
}

int	screen_close(t_data *data)
{
	ft_free_all(data, 0);
	exit(0);
}
