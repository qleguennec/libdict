/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 02:29:29 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/09 06:13:26 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

int			dict_del(t_dict *d, char *key)
{
	t_dict_ent	*ent;

	if (!(ent = dict_find_ent(d, key)))
		return (0);
	ent->key = NULL;
	ent->val.used = 0;
	d->used--;
	return (1);
}
