/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_find_match.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 07:43:30 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/12 21:30:16 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

t_dict_ent	*dict_find_match(t_dict *d, void *key, int type)
{
	size_t	i;
	long	j;

	i = d->hash_f(key) % d->total;
	j = 0;
	while (dict_istype(&d->ents[i], type))
	{
		if (MATCH(d->ents[i], key))
			return (&d->ents[i]);
		j++;
		i = (i + j * j) % d->total;
	}
	return (NULL);
}
