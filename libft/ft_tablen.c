/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:09:15 by hamzaelouar       #+#    #+#             */
/*   Updated: 2024/01/11 13:05:35 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_tablen(char **arr)
{
	size_t	len;
	
	len = 0;
	while (arr[len])
		len++;
	return (len);
}
