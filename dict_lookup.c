/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_lookup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:46:39 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 06:49:41 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

t_dict_ent		*dict_lookup(t_dict *d, void *key)
{
	size_t		i;
	long		j;

	i = d->hashf(key) % d->total;
	j = 0;
	while (USED(d->ents[i]))
	{
		if (MATCH(d->ents[i], key))
			return (&d->ents[i]);
		j++;
		i = (i + j * j) % d->total;
	}
	return (NULL);
}
