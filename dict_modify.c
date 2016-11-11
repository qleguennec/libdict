/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_modify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:20:01 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 20:43:17 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdict.h"

int			dict_modify
	(t_dict *d, void *key, int type, void (*f)(t_dict *, t_dict_ent *))
{
	t_dict_ent	*ent;

	dict_regen(d);
	ent = dict_find_match(d, key, type);
	if (!ent)
		return (0);
	f(d, ent);
	return (1);
}
