/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_ent_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:21:02 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 14:35:09 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void		dict_ent_free(t_dict *d, t_dict_ent *ent)
{
	if (USED((*ent)))
		d->used--;
	if (DELETED((*ent)))
		d->del--;
	ent->val.used = 0;
	free(ent->val.data);
	ent->key = NULL;
}
