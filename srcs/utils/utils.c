/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:18:05 by hamzaelouar       #+#    #+#             */
/*   Updated: 2024/01/11 14:03:18 by hel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	space_or_x(char *str)
{
	while (*str)
	{
		if (*str == 'x')
			str++;
		else if (*str == '\n')
			str++;
		else
			return (0);
	}
	return (1);
}

int	count_space(char **str, int *i)
{
	int	cpt;

	cpt = 0;
	while (space_or_x(str[*i]))
	{
		(*i)++;
		cpt++;
	}
	return (cpt);
}

void	assign_fd(t_data *data, int cl, int fd)
{
	if (cl == 0)
		data->parse->fdmap = fd;
	else if (cl == 1)
		data->parse->fdn = fd;
	else if (cl == 2)
		data->parse->fds = fd;
	else if (cl == 3)
		data->parse->fde = fd;
	else if (cl == 4)
		data->parse->fdw = fd;
}
