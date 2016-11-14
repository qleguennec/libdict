/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:48:21 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/14 14:51:37 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

size_t	dict_size(t_dict *d, int type)
{
	if (type & DICT_DELETED)
		return (d->del);
	if (type & DICT_USED)
		return (d->used);
	if (type & DICT_EXIST)
		return (d->del + d->used);
	if (type & DICT_EMPTY)
		return (d->total - d->del - d->used);
	if (type & DICT_AVAIL)
		return (d->total - d->used);
	return (0);
}
