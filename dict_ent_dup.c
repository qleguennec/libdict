/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_ent_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 03:15:20 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 21:41:53 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void	dict_ent_dup(t_dict *d, t_dict_ent *ent)
{
	t_dict_ent	*slot;

	dict_regen(d);
	slot = dict_find_ent(d, ent->key, DICT_USED);
	if (DELETED((*slot)))
		d->del--;
	slot->key = ent->key;
	slot->val = ent->val;
	d->used++;
}
