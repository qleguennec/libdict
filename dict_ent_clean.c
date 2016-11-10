/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_ent_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:21:02 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 20:52:29 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void		dict_ent_clean(t_dict *d, t_dict_ent *ent)
{
	if (USED((*ent)))
		dict_ent_del(d, ent);
	if (DELETED((*ent)))
	{
		free(ent->val.data);
		ent->val.total = 0;
		d->del--;
	}
	ent->key = NULL;
}
