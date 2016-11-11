/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 02:29:29 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 03:22:26 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

void		dict_del(t_dict *d)
{
	t_dict_ent	*ent;
	size_t		n;

	ent = d->ents;
	n = 0;
	while (dict_iter(d, &ent, &n, DICT_EXIST))
		dict_ent_del(d, ent++);
}
