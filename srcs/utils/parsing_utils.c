/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:44:47 by hel-ouar          #+#    #+#             */
/*   Updated: 2024/01/10 14:19:18 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_color(char **split_color, char *color, int i, int nb)
{
	if (color[0] == ',' || color[ft_strlen(color) - 2] == ',')
		return (1);
	while (color[i] != '\n')
	{
		if (color[i] == ',' && color[i + 1] && color[i + 1] == ',')
			return (1);
		else if ((color[i] == ',' && color[i + 1] != ',' && color[i + 1]))
		{
			i++;
			continue ;
		}
		else if (!ft_isdigit(color[i]))
			return (1);
		i++;
	}
	i = -1;
	while (split_color[++i])
	{
		nb = ft_atoi(split_color[i]);
		if (nb < 0 || nb > 255)
			return (1);
	}
	if (i != 3)
		return (1);
	return (0);
}

int	check_char(char *str, int *p, t_parse *parse)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ' && \
		str[i] != '\n' && str[i] != 'N' && str[i] != 'S' && \
		str[i] != 'E' && str[i] != 'W')
			return (1);
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
		{
			parse->orientation = str[i];
			*p += 1;
		}
		i++;
	}
	return (0);
}

void	space_to_x(char *line)
{
	while (*line)
	{
		if (*line == ' ')
			*line = 'x';
		line++;
	}
}

int	no_wall_or_space(char *str)
{
	while (*str && *str != '\n')
	{
		if (*str != '1')
		{
			if (*str != 'x')
				return (1);
		}
		str++;
	}
	return (0);
}

int	is_player(char p)
{
	if (p == 'N' || p == 'S' || p == 'E' || p == 'W')
		return (1);
	return (0);
}

