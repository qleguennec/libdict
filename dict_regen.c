/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_regen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 03:33:32 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 03:12:39 by qle-guen         ###   ########.fr       */
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
	dict_cpy(new, d);
}

void			dict_regen(t_dict *d, int grow)
{
	size_t		newsize;
	t_dict		new;

	if (grow)
		newsize = d->total < 10 ? 16 : d->total * GROWTH_FACTOR;
	else
		newsize = d->total;
	dict_init(&new, newsize, d->hash_f, d->cmp_f);
	fill(d, &new);
	d->total = new.total;
	d->used = new.used;
	free(d->ents);
	d->ents = new.ents;
}
