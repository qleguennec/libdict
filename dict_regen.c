/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_regen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 03:33:32 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 20:59:33 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

size_t			newsize(t_dict *d)
{
	if (d->total == 1)
		return (16);
	if ((float)(d->used + d->del) / (float)d->total > GROW_THRESHOLD)
		return (d->total * GROWTH_FACTOR);
	if ((float)d->del / (float)d->used > REGEN_THRESHOLD)
		return (d->total);
	return (0);
}

void			dict_regen(t_dict *d)
{
	size_t		size;
	t_dict		new;

	if (!(size = newsize(d)))
		return ;
	dict_init(&new, size, d->hash_f, d->cmp_f);
	dict_map(d, DICT_DELETED, &dict_ent_free);
	dict_map2(d, &new, DICT_USED, &dict_ent_dup);
	free(d->ents);
	ft_memcpy(d, &new, sizeof(*d) - sizeof(*d->free));
}
