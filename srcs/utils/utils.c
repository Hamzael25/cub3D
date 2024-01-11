/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalzentout <bilalzentout@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:18:05 by hamzaelouar       #+#    #+#             */
/*   Updated: 2024/01/10 19:12:14 by bilalzentou      ###   ########.fr       */
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
