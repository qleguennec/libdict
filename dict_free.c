/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 05:14:12 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 00:01:40 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"
#include "libdict_intern.h"

void		dict_free(t_dict *d)
{
	t_dict_ent	*ent;
	size_t		n;

	n = 0;
	ent = d->ents;
	while (dict_iter(d, &ent, &n))
	{
		dict_ent_del(d, ent);
		ent->val.total = 0;
		free(ent->val.data);
		ent++;
	}
	free(d->ents);
	d->used = 0;
	d->total = 0;
	lstfree(d->fl);
}
