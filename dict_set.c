/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:06:02 by qle-guen          #+#    #+#             */
/*   Updated: 2017/03/31 11:16:00 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void		dict_set(t_dict *d, void *key, void *val, size_t size)
{
	t_dict_ent		*ent;

	if (!size)
		return ;
	ent = dict_find_maybe(d, key, DICT_EXIST);
	if (!USED((*ent)))
		d->used++;
	if (DELETED((*ent)))
		d->del--;
	ent->key = key;
	ent->val.used = 0;
	vect_add(&ent->val, val, size);
	dict_regen(d);
}
