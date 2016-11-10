/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:29:10 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 19:17:37 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

static int	iter_type(t_dict_ent *ent, int type)
{
	if (type == DICT_EMPTY)
		return (EMPTY((*ent)));
	if (type == DICT_AVAIL)
		return (AVAIL((*ent)));
	if (type == DICT_EXIST)
		return (EXIST((*ent)));
	if (type == DICT_DEL)
		return (DELETED((*ent)));
	if (type == DICT_USED)
		return (USED((*ent)));
	return (0);
}

static int	size_cmp(t_dict *d, size_t n, int type)
{
	size_t	cmp;

	if (type == DICT_USED)
		cmp = d->used;
	else if (type == DICT_EXIST)
		cmp = d->del + d->used;
	else if (type == DICT_AVAIL)
		cmp = d->total - d->used;
	else if (type == DICT_DEL)
		cmp = d->del;
	else if (type == DICT_EMPTY)
		cmp = d->total - d->used - d->del;
	else
		return (0);
	return (n > cmp);
}

int			dict_iter(t_dict *d, t_dict_ent **ent, size_t *n, int type)
{
	if (size_cmp(d, *n, type))
		return (0);
	while ((size_t)(*ent - d->ents) < d->total)
	{
		if (iter_type(*ent, type))
		{
			(*n)++;
			return (1);
		}
		(*ent)++;
	}
	return (0);
}
