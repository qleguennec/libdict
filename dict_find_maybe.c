/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_find_maybe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 21:27:17 by qle-guen          #+#    #+#             */
/*   Updated: 2017/03/31 11:16:01 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

t_dict_ent	*dict_find_maybe(t_dict *d, void *key, int type)
{
	size_t	i;
	long	j;

	i = d->hash_f(key) % d->total;
	j = 0;
	while (dict_istype(&d->ents[i], type))
	{
		if (EXIST(d->ents[i]) && MATCH(d->ents[i], key))
			return (&d->ents[i]);
		j++;
		i = (i + j * j) % d->total;
	}
	return (&d->ents[i]);
}
