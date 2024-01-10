/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_ctx_wild_manip.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:05:07 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/11/27 01:59:04 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gc_internal.h"

void	ft_gc_ctx_release(t_ctx *ctx, t_ptr p)
{
	ft_gc_ctx_transfer(_get_wild(), ctx, p);
}

void	ft_gc_ctx_release_all(t_ctx *ctx)
{
	ft_gc_ctx_transfer_all(_get_wild(), ctx);
}

void	ft_gc_ctx_obtain_wild(t_ctx *ctx)
{
	ft_gc_ctx_transfer_all(ctx, _get_wild());
}
