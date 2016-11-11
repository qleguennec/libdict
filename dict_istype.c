/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_istype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:14:20 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 20:01:23 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

int		dict_istype(t_dict_ent *ent, int type)
{
	if (type == DICT_DELETED)
		return (DELETED((*ent)));
	if (type == DICT_USED)
		return (USED((*ent)));
	if (type == DICT_EXIST)
		return (EXIST((*ent)));
	if (type == DICT_EMPTY)
		return (EMPTY((*ent)));
	if (type == DICT_AVAIL)
		return (AVAIL((*ent)));
	return (0);
}
