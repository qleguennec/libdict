/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:29:10 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 13:05:46 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

static int		iter_type(t_dict_ent *ent, int type)
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

int				dict_iter(t_dict *d, t_dict_ent **ent, int type)
{
	while ((size_t)(*ent - d->ents) < d->total)
	{
		if (iter_type(*ent, type))
			return (1);
		(*ent)++;
	}
	return (0);
}
