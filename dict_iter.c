/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:29:10 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 16:49:30 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

int				dict_iter(t_dict *d, t_dict_ent **ent, int type)
{
	while ((size_t)(*ent - d->ents) < d->total)
	{
		if (dict_istype(*ent, type))
			return (1);
		(*ent)++;
	}
	return (0);
}
