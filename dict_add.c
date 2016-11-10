/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:53:07 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 20:07:42 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void		dict_add(t_dict *d, void *key, void *val, size_t size)
{
	t_dict_ent	*ent;

	ent = dict_find_empty(d, key);
	ent->key = key;
	vect_add(&ent->val, val, size);
	d->used++;
	if ((float)d->used / (float)d->total > GROW_TRESHOLD)
		dict_regen(d, 1);
}
