/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:06:02 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 21:24:59 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void		dict_set(t_dict *d, void *key, void *val, size_t size)
{
	t_dict_ent		*ent;

	if (!size)
		return ;
	ent = dict_lookup(d, key);
	if (!ent)
		return (dict_add(d, key, val, size));
	dict_regen(d);
	if (DELETED((*ent)))
		d->del--;
	ent->val.used = 0;
	vect_add(&ent->val, val, size);
	d->used++;
}
