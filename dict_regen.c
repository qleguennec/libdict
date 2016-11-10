/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_regen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 03:33:32 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 17:37:44 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void	dict_regen(t_dict *d, size_t grow)
{
	t_dict		new;
	size_t		i;

	dict_init(&new, d->total + grow * DICT_GROWTH_FACTOR, d->hash_f, d->cmp_f);
	i = 0;
	while (i < d->total)
	{
		if (USED(d->ents[i]))
			dict_vect_add(&new, d->ents[i].key, d->ents[i].val);
		else if (DELETED(d->ents[i]))
			d->del--;
		i++;
	}
	d->total = new.total;
	d->used = new.used;
	free(d->ents);
	d->ents = new.ents;
}
