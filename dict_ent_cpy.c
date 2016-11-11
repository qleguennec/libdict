/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_ent_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 02:55:37 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 03:13:18 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void		dict_ent_cpy(t_dict *d, t_dict_ent *ent)
{
	t_dict_ent	*new;

	if ((float)d->used / (float)d->total > GROW_TRESHOLD)
		dict_regen(d, 1);
	new = dict_find_empty(d, ent->key);
	if (DELETED((*new)))
		d->del--;
	new->key = ent->key;
	new->val = ent->val;
	d->used++;
}
