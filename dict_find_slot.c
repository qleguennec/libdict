/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_find_slot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:35:37 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 06:49:34 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

size_t		dict_find_slot(t_dict *d, void *key)
{
	size_t	i;
	long	j;

	i = d->hashf(key) % d->total;
	j = 0;
	while (!AVAIL(d->ents[i]))
	{
		j++;
		i = (i + j * j) % d->total;
	}
	return (i);
}
