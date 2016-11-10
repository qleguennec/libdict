/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_vect_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 02:55:37 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 17:46:23 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void		dict_vect_add(t_dict *d, void *key, t_vect val)
{
	t_dict_ent	*ent;

	ent = dict_find_empty(d, key);
	d->used++;
	ent->key = key;
	ent->val = val;
	if ((float)d->used / (float)d->total > GROW_TRESHOLD)
		dict_regen(d, 1);
}
