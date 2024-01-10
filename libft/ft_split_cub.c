/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:00:21 by hamzaelouar       #+#    #+#             */
/*   Updated: 2024/01/10 14:27:36 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_malloc_clear(char **strs, int a)
{
	if (!strs[a])
	{
		while (a >= 0)
		{
			free(strs[a]);
			a--;
		}
		free(strs);
		return (1);
	}
	return (0);
}

static int	ft_wordcount(char const *s, char c)
{
	int	wordcount;
	int	i;

	wordcount = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
		}
		if (s[i] == '\0')
			break ;
		while (s[i] && s[i] != c)
			i++;
		wordcount++;
	}
	return (wordcount);
}

static char	**ft_spliit(char const *s, char **final, char c, int i)
{
	int	begin;
	int	j;

	begin = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			while (s[i] == c)
				i++;
		if (s[i] == '\0')
			break ;
		begin = i;
		while (s[begin] && s[begin] != c)
			begin ++;
		final[j] = ft_substr(s, i, begin - i);
		if (j <= ft_wordcount(s, c) && ft_malloc_clear(final, j))
			return (NULL);
		j++;
		i = begin;
	}
	return (final);
}

char	**ft_split_cub(char const *s, char c)
{
	char	**final;

	if (!s)
		return (0);
	final = ft_calloc(sizeof(char *), ft_wordcount(s, c) + 1);
	if (!final)
		return (NULL);
	return (ft_spliit(s, final, c, 0));
}

