/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_regen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 03:33:32 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 14:59:14 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void			dict_regen(t_dict *d, int grow)
{
	size_t		newsize;
	t_dict		new;

	if (grow)
		newsize = d->total < 10 ? 16 : d->total * GROWTH_FACTOR;
	else
		newsize = d->total;
	dict_init(&new, newsize, d->hash_f, d->cmp_f);
	dict_map2(d, &new, DICT_USED, &dict_ent_add);
	dict_map(d, DICT_EXIST, &dict_ent_free);
	d->total = new.total;
	d->used = new.used;
	d->del = 0;
	free(d->ents);
	d->ents = new.ents;
}
