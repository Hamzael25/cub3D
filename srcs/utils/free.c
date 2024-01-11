/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:44:47 by hel-ouar          #+#    #+#             */
/*   Updated: 2024/01/11 13:15:39 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_free_all(t_data *data, int mod)
{
	free_win(data, mod);
	free_parse(data->parse);
	free_struct(data);
}

void	free_struct(t_data *data)
{
	if (data->parse)
		free(data->parse);
	if (data->play)
		free(data->play);
	if (data->win)
		free(data->win);
	if (data->no_text)
		free(data->no_text);
	if (data->so_text)
		free(data->so_text);
	if (data->ea_text)
		free(data->ea_text);
	if (data->we_text)
		free(data->we_text);
	if (data->stage)
		free(data->stage);
}

void	free_parse(t_parse *parse)
{
	if (parse)
	{
		if (parse->map)
			ft_free_tab(parse->map);
		if (parse->no)
			free(parse->no);
		if (parse->so)
			free(parse->so);
		if (parse->ea)
			free(parse->ea);
		if (parse->we)
			free(parse->we);
	}
}

void	free_win(t_data *data, int mod)
{
	if (data->win)
	{
		if (data->no_text && data->no_text->img)
			mlx_destroy_image(data->win->mlx, data->no_text->img);
		if (data->so_text && data->so_text->img)
			mlx_destroy_image(data->win->mlx, data->so_text->img);
		if (data->we_text && data->we_text->img)
			mlx_destroy_image(data->win->mlx, data->we_text->img);
		if (data->ea_text && data->ea_text->img)
			mlx_destroy_image(data->win->mlx, data->ea_text->img);
		if (data->win->img && mod)
			mlx_destroy_image(data->win->mlx, data->win->img);
		if (data->win->mlx_w)
			mlx_destroy_window(data->win->mlx, data->win->mlx_w);
		if (data->win->mlx)
			mlx_destroy_display(data->win->mlx);
	}
}
