/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_regen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 03:33:32 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 20:08:27 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void	dict_regen(t_dict *d, size_t grow)
{
	t_dict		new;
	size_t		i;

	if (d->total == 1)
		grow = 4;
	else
		grow = grow ? grow * DICT_GROWTH_FACTOR * d->total : d->total;
	dict_init(&new, grow, d->hash_f, d->cmp_f);
	i = 0;
	while (i < d->total)
	{
		if (USED(d->ents[i]))
			dict_vect_add(&new, d->ents[i].key, d->ents[i].val);
		else if (DELETED(d->ents[i]))
		{
			d->ents[i].val.used = 0;
			d->del--;
		}
		i++;
	}
	d->total = new.total;
	d->used = new.used;
	free(d->ents);
	d->ents = new.ents;
}
