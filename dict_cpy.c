/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_cpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:54:37 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 02:58:21 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict_intern.h"

void		dict_cpy(t_dict *dest, t_dict *src)
{
	t_dict_ent	*ent;
	size_t		n;

	n = 0;
	ent = src->ents;
	while (dict_iter(src, &ent, &n, DICT_USED))
	{
		dict_vect_add(dest, ent->key, ent->val);
		ent++;
	}
}
