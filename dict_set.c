/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:31:25 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 02:34:33 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

void		dict_set(t_dict *d, void *key, void *val, size_t size)
{
	t_dict_ent	*ent;

	ent = dict_find_match(d, key);
	if (!ent)
		return (dict_add(d, key, val, size));
	ent->val.used = 0;
	vect_add(&ent->val, val, size);
}
