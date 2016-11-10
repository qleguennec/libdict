/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 02:29:29 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/10 07:48:56 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

int			dict_del(t_dict *d, void *key)
{
	t_dict_ent	*ent;

	ent = dict_find_match(d, key);
	if (!ent)
		return (0);
	dict_ent_del(d, ent);
	return (1);
}
