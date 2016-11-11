/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:48:21 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 12:51:05 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

size_t   dict_size(t_dict *d, int type)
{
		if (type == DICT_USED)
			return (d->used);
		else if (type == DICT_EXIST)
			return (d->del + d->used);
		else if (type == DICT_AVAIL)
			return (d->total - d->used);
		else if (type == DICT_DEL)
			return (d->del);
		else if (type == DICT_EMPTY)
			return (d->total - d->used - d->del);
		return (-1);
}
