/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:06:02 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/12 01:18:13 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void		dict_set(t_dict *d, void *key, void *val, size_t size)
{
	t_dict_ent		*ent;

	if (!size)
		return ;
	dict_regen(d);
	ent = dict_find_match(d, key, DICT_EXIST);
	if (!ent)
		return (dict_add(d, key, val, size));
	if (DELETED((*ent)))
	{
		d->del--;
		d->used++;
	}
	ent->key = key;
	ent->val.used = 0;
	vect_add(&ent->val, val, size);
}
