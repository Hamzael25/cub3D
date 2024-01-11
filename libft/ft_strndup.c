/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalzentout <bilalzentout@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:08:57 by hel-ouar          #+#    #+#             */
/*   Updated: 2024/01/10 19:11:10 by bilalzentou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *s, size_t n)
{
	char	*new;

	new = malloc(n + 1);
	if (new)
	{
		ft_strncpy(new, s, n);
		new[n] = '\0';
	}
	return (new);
}
