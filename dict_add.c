/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:53:07 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/12 17:23:18 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void		dict_add(t_dict *d, void *key, void *val, size_t size)
{
	t_dict_ent	*ent;

	if (!size)
		return ;
	dict_regen(d);
	ent = dict_find_ent(d, key, DICT_USED);
	if (DELETED((*ent)))
		d->del--;
	ent->key = key;
	ent->val.used = 0;
	vect_add(&ent->val, val, size);
	d->used++;
}
