/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 05:14:12 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/09 06:30:03 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"
#include "libdict_intern.h"

void		dict_free(t_dict *d)
{
	size_t	i;

	i = -1;
	while (++i < d->total)
	{
		free(d->ents[i].val.data);
		d->ents[i].val.total = 0;
		d->ents[i].val.used = 0;
	}
	free(d->ents);
	d->used = 0;
	d->total = 0;
	lstfree(d->fl);
}
