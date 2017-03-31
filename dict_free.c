/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:25:17 by qle-guen          #+#    #+#             */
/*   Updated: 2017/03/31 14:18:30 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

static void
	listfree
	(t_list *l)
{
	t_list	*next;

	if (l)
	{
		next = l->next;
		free(l->p);
		free(l);
		listfree(next);
	}
}

void
	dict_free
	(t_dict *d)
{
	dict_clear(d);
	dict_map(d, DICT_DELETED, &dict_ent_free);
	free(d->ents);
	listfree(d->free);
}
