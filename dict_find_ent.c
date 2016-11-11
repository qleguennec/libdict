/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_find_ent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:35:37 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 20:24:38 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

t_dict_ent	*dict_find_ent(t_dict *d, void *key, int type)
{
	size_t	i;
	long	j;

	i = d->hash_f(key) % d->total;
	j = 0;
	while (dict_istype(&d->ents[i], type))
	{
		j++;
		i = (i + j * j) % d->total;
	}
	return (&d->ents[i]);
}
