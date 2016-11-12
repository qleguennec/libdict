/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_ent_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 21:15:40 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/12 21:22:00 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void	dict_ent_cpy(t_dict *d, t_dict_ent *new)
{
	t_dict_ent	*ent;

	ent = dict_find_ent(d, new->key, DICT_USED);
	if (DELETED((*ent)))
		dict_ent_free(d, ent);
	ft_memcpy(ent, new, sizeof(*ent));
	d->used++;
	dict_regen(d);
}
