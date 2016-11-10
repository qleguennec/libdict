/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:29:10 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 05:00:31 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

int		dict_iter(t_dict *d, t_dict_ent **ent, size_t *n)
{
	if (*n > d->used)
		return (0);
	while ((size_t)(*ent - d->ents) < d->total)
	{
		if (USED((**ent)))
		{
			(*n)++;
			return (1);
		}
		(*ent)++;
	}
	return (0);
}
