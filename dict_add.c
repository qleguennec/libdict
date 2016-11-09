/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:53:07 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/09 22:38:48 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

void		dict_add(t_dict *d, void *key, void *val, size_t size)
{
	t_dict_ent	*ent;

	ent = dict_find_ent(d, key);
	if (ent->key)
	{
		ent->val.used = 0;
		vect_add(&ent->val, val, size);
		return ;
	}
	ent->key = key;
	vect_add(&ent->val, val, size);
	d->used++;
	if (d->used / d->total > GROW_TRESHOLD)
		dict_grow(d);
}
