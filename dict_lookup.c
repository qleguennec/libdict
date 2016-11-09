/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_lookup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:46:39 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/09 03:01:54 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

t_dict_ent		*dict_lookup(t_dict *d, void *key)
{
	size_t		i;
	t_dict_ent	*ret;

	i = dict_find_slot(d, key);
	ret = d->ents + i;
	return (ret->key ? ret : NULL);
}
