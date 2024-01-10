/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_static.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:05:43 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/10/31 08:05:45 by hel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gc_internal.h"

void	_init_ctx(t_ctx *ctx)
{
	char	*p;
	size_t	i;

	p = (char *)ctx;
	i = 0;
	while (i < sizeof(t_ctx))
		p[i++] = 0;
}

t_ctx	*_get_global(void)
{
	static t_ctx	global;
	static int		init = 0;

	if (!init)
	{
		_init_ctx(&global);
		init = 1;
	}
	return (&global);
}

t_ctx	*_get_wild(void)
{
	static t_ctx	wild;
	static int		init = 0;

	if (!init)
	{
		_init_ctx(&wild);
		init = 1;
	}
	return (&wild);
}

t_ctx	**_get_local_start(void)
{
	static t_ctx	*local = NULL;

	return (&local);
}
