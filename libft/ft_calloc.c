/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:52:07 by hel-ouar          #+#    #+#             */
/*   Updated: 2024/01/10 14:26:35 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	if (count != 0 && SIZE_MAX / count < size)
		return (0);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

// void	*ft_calloc_child(size_t count, size_t size)
// {
// 	char	*ptr;

// 	if (count != 0 && SIZE_MAX / count < size)
// 		return (0);
// 	ptr = (void *)ft_gc_malloc(count * size);
// 	if (!ptr)
// 		exit_child(-1);
// 	ft_bzero(ptr, count * size);
// 	return (ptr);
// }

// void	*ft_calloc_parent(size_t count, size_t size, char *str)
// {
// 	char	*ptr;

// 	if (count != 0 && SIZE_MAX / count < size)
// 		return (0);
// 	ptr = (void *)ft_gc_malloc(count * size);
// 	if (!ptr)
// 		exit_parent(str);
// 	ft_bzero(ptr, count * size);
// 	return (ptr);
// }
