/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalzentout <bilalzentout@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:44:23 by hel-ouar          #+#    #+#             */
/*   Updated: 2024/01/10 19:11:06 by bilalzentou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_bis;
	unsigned char	*s2_bis;
	size_t			i;

	i = 0;
	s1_bis = (unsigned char *)s1;
	s2_bis = (unsigned char *)s2;
	while (i != n && (s1_bis[i] != '\0' || s2_bis[i] != '\0'))
	{
		if (s1_bis[i] != s2_bis[i])
		{
			return (s1_bis[i] - s2_bis[i]);
		}
		i++;
	}
	return (0);
}
