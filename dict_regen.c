/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_regen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 03:33:32 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 21:10:52 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

static void		fill(t_dict *d, t_dict *new)
{
	t_dict_ent	*ent;
	size_t		n;

	n = 0;
	ent = d->ents;
	while (dict_iter(d, &ent, &n, DICT_DEL))
	{
		ent->key = NULL;
		free(ent++->val.data);
	}
	d->del = 0;
	n = 0;
	ent = d->ents;
	while (dict_iter(d, &ent, &n, DICT_USED))
	{
		dict_vect_add(new, ent->key, ent->val);
		ent++;
	}
}

void			dict_regen(t_dict *d, size_t grow)
{
	t_dict		new;

	if (d->total == 1)
		grow = 4;
	else
		grow = grow ? grow * DICT_GROWTH_FACTOR * d->total : d->total;
	dict_init(&new, grow, d->hash_f, d->cmp_f);
	fill(d, &new);
	d->total = new.total;
	d->used = new.used;
	free(d->ents);
	d->ents = new.ents;
}
