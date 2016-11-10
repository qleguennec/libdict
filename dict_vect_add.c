/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_vect_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 02:55:37 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 23:09:49 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void		dict_vect_add(t_dict *d, void *key, t_vect val)
{
	t_dict_ent	*ent;

	if ((float)d->used / (float)d->total > GROW_TRESHOLD)
		dict_regen(d, 1);
	ent = dict_find_empty(d, key);
	if (DELETED((*ent)))
		d->del--;
	ent->key = key;
	ent->val = val;
	d->used++;
}
